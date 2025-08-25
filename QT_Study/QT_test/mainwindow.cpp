#include "mainwindow.h"
#include "ui_mainwindow.h"
//图片类
#include <QIcon>
#include <QPixmap>
#include <QPalette>
//文件系统
#include <QDir>
#include <QFile>
#include <QFileInfo>
//对话窗口
#include <QMessageBox>
//随机数部分
#include <time.h>
//打印调试
#include <QDebug>
//动画效果
#include <QPropertyAnimation>
#include <chrono>
#include <iomanip>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_player(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
    , m_MODE(ORDER_MODE)
    , m_musicDir("F:\\QT_Study\\QT_test\\songs\\")
    , m_isShowFlag(false)
    , m_isSliderBeingDragged(false)
    , m_wasPlayingBeforeDrag(false)
    , m_isPlaying(false)
    , m_isDraggingProgress(false)
    , m_currentBackgroundIndex(0)
{
    ui->setupUi(this);
    setFixedSize(900, 600);
    setWindowTitle("音乐播放器摩西摩西");
    setBackGround(":/image/background_1.jpg");

    m_player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.7);
    audioOutput->setMuted(false);

    loadAppointMusicDir(m_musicDir);
    startPlayMusic();

    ui->playBtn->setIcon(QIcon(":/icon/play.png"));
    srand(time(NULL));

    initButton();

    connect(m_player, &QMediaPlayer::playbackStateChanged, this, [this](QMediaPlayer::PlaybackState state) {
        m_isPlaying = (state == QMediaPlayer::PlayingState);
        updatePlayButtonIcon();
    });

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            handleNextSlot();
        }
    });
    initBackground();
    loadBackgroundImages();
    setBackGround(m_backgroundImages[m_currentBackgroundIndex]);  // 设置初始背景
}

MainWindow::~MainWindow()
{
    delete ui;
}


// 切换到下一张背景图片
void MainWindow::switchToNextBackground()
{
    if (m_backgroundImages.isEmpty()) {
        QMessageBox::warning(this, "背景", "未找到背景图片");
        return;
    }

    // 切换到下一张（循环切换）
    m_currentBackgroundIndex = (m_currentBackgroundIndex + 1) % m_backgroundImages.size();
    setBackGround(m_backgroundImages[m_currentBackgroundIndex]);

    // 显示当前背景名称
    QFileInfo fileInfo(m_backgroundImages[m_currentBackgroundIndex]);
    QMessageBox::information(this, "背景", "已切换到：" + fileInfo.fileName());
}

// 修改setBackGround函数以支持资源路径
void MainWindow::setBackGround(const QString& filename)
{
    QPixmap pixmap(filename);
    if (pixmap.isNull()) {
        qDebug() << "无法加载背景图片：" << filename;
        return;
    }

    QSize windowSize = this->size();
    QPixmap scaledPixmap = pixmap.scaled(windowSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));
    this->setPalette(palette);
}

void MainWindow::loadBackgroundImages()
{
    // 使用QDir读取资源路径下的图片
    QDir dir(":/image");
    if (!dir.exists()) {
        qDebug() << "背景图片文件夹不存在";
        return;
    }

    // 筛选图片文件
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp";
    dir.setNameFilters(filters);

    // 获取所有图片路径
    QFileInfoList fileList = dir.entryInfoList();
    for (const QFileInfo &fileInfo : fileList) {
        m_backgroundImages.append(fileInfo.absoluteFilePath());
    }

    if (m_backgroundImages.isEmpty()) {
        qDebug() << "未找到背景图片";
    } else {
        qDebug() << "加载了" << m_backgroundImages.size() << "张背景图片";
    }
}

void MainWindow::initBackground()
{
    connect(ui->changeBgBtn, &QPushButton::clicked, this, &MainWindow::switchToNextBackground);
}

QString MainWindow::formatTime(int milliseconds)
{
    auto duration = std::chrono::milliseconds(milliseconds);
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count() % 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;

    return QString::fromStdString(oss.str());
}

void MainWindow::showAnimation(QWidget* window)
{
    QPropertyAnimation animation(window, "pos");
    animation.setDuration(200);
    animation.setStartValue(QPoint(this->width(), 0));
    animation.setEndValue(QPoint(this->width() - ui->musicList->width(), 0));
    animation.start();
    QEventLoop loop;
    connect(&animation, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::closeAnimation(QWidget* window)
{
    QPropertyAnimation animation(window, "pos");
    animation.setDuration(200);
    animation.setStartValue(QPoint(this->width() - ui->musicList->width(), 0));
    animation.setEndValue(QPoint(this->width(), 0));
    animation.start();
    QEventLoop loop;
    connect(&animation, &QPropertyAnimation::finished, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::musicListSlot()
{
    if (!m_isShowFlag)
    {
        ui->musicList->show();
        showAnimation(ui->musicList);
    }
    else
    {
        closeAnimation(ui->musicList);
        ui->musicList->hide();
    }
    m_isShowFlag = !m_isShowFlag;
}

void MainWindow::initButton()
{
    //绑定图标
    setButtonStyle(ui->prevBtn, ":/icon/prev.png");
    setButtonStyle(ui->playBtn, ":/icon/play.png");
    setButtonStyle(ui->nextBtn, ":/icon/next.png");
    setButtonStyle(ui->modeBtn, ":/icon/shun.png");
    setButtonStyle(ui->listBtn, ":/icon/list.png");
    setButtonStyle(ui->changeBgBtn, ":/icon/background.png");

    //绑定信号和槽
    connect(ui->playBtn, &QPushButton::clicked, this, &MainWindow::handlePlaySlot);
    connect(ui->modeBtn, &QPushButton::clicked, this, &MainWindow::handleModeSlot);
    connect(ui->nextBtn, &QPushButton::clicked, this, &MainWindow::handleNextSlot);
    connect(ui->prevBtn, &QPushButton::clicked, this, &MainWindow::handlePrevSlot);
    connect(ui->listBtn, &QPushButton::clicked, this, &MainWindow::musicListSlot);

    //进度时间绑定
    connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::handlePositionSlot);
    connect(m_player, &QMediaPlayer::durationChanged, this, &MainWindow::handleDurationSlot);

    // 进度条拖动相关信号
    connect(ui->progressBar, &QSlider::sliderPressed, this, &MainWindow::on_progressBar_sliderPressed);
    connect(ui->progressBar, &QSlider::sliderReleased, this, &MainWindow::on_progressBar_sliderReleased);
    connect(ui->progressBar, &QSlider::sliderMoved, this, &MainWindow::on_progressBar_sliderMoved);
    connect(ui->volume_slider, &QSlider::valueChanged, this, &MainWindow::on_volume_slider_valueChanged);

    // 设置音乐列表样式
    ui->musicList->setStyleSheet("QListWidget{"
                                 "border:none;"
                                 "border-radius:20px;"
                                 "background-color:rgba(255,255,255,0.7);}");
    ui->musicList->hide();

    //初始化音量条
    ui->volume_slider->setRange(0, 100);  // 设置范围为0-100
    ui->volume_slider->setValue(70);     // 默认70%音量
    ui->volume->setText("音量:70");    // 设置音量标签

    // 设置音乐列表样式
    ui->musicList->setStyleSheet(R"(
        QListWidget {
            background-color: rgba(255, 255, 255, 0.8);
            border-radius: 10px;
            border: none;
            font-family: "Microsoft YaHei";
            font-size: 14px;
            color: #333;
            padding: 5px;
        }
        QListWidget::item {
            height: 40px;
            border-radius: 6px;
            margin: 3px;
        }
        QListWidget::item:selected {
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #409EFF, stop:1 #66B1FF);
            color: white;
        }
        QListWidget::item:hover {
            background-color: #E6F3FF;
        }
    )");
}

void MainWindow::updateVolumeDisplay(int volume)
{
    ui->volume->setText(QString("音量: %1%").arg(volume));
}

void MainWindow::on_volume_slider_valueChanged(int value)
{
    // 更新音量显示
    updateVolumeDisplay(value);

    // 设置实际音量 (QAudioOutput的音量范围是0.0-1.0)
    qreal volume = value / 100.0;
    audioOutput->setVolume(volume);
}

void MainWindow::handleDurationSlot(int duration)
{
    if (duration > 0)
        ui->progressBar->setRange(0, duration);
    ui->label_2->setText(formatTime(duration));
}

void MainWindow::handlePositionSlot(int position)
{
    if (!m_isDraggingProgress) {
        ui->progressBar->setValue(position);
        ui->label_1->setText(formatTime(position));
    }
}

void MainWindow::startPlayMusic()
{
    if (ui->musicList->count() > 0) {
        QString currentMusic = m_musicDir + ui->musicList->currentItem()->text() + ".mp3";
        qDebug() << "Loading music:" << currentMusic;
        m_player->setSource(QUrl::fromLocalFile(currentMusic));
        // 不自动播放，等待用户点击播放按钮
    } else {
        qDebug() << "No music items in the list!";
    }
}

void MainWindow::handlePrevSlot()
{
    if (ui->musicList->count() <= 0) return;

    int currentRow = ui->musicList->currentRow();
    int nextRow = 0;

    if (m_MODE == ORDER_MODE) {
        nextRow = (currentRow - 1 + ui->musicList->count()) % ui->musicList->count();
    } else if (m_MODE == RANDOM_MODE) {
        int cnt = 0;
        do {
            nextRow = rand() % ui->musicList->count();
            cnt++;
        } while (cnt < 3 && nextRow == currentRow);
    } else {
        nextRow = currentRow;
    }

    ui->musicList->setCurrentRow(nextRow);
    startPlayMusic();

    // 如果之前是播放状态，则继续播放
    if (m_isPlaying) {
        m_player->play();
    }
}

void MainWindow::handleNextSlot()
{
    if (ui->musicList->count() <= 0) return;

    int currentRow = ui->musicList->currentRow();
    int nextRow = 0;

    if (m_MODE == ORDER_MODE) {
        nextRow = (currentRow + 1) % ui->musicList->count();
    } else if (m_MODE == RANDOM_MODE) {
        int cnt = 0;
        do {
            nextRow = rand() % ui->musicList->count();
            cnt++;
        } while (cnt < 3 && nextRow == currentRow);
    } else {
        nextRow = currentRow;
    }

    ui->musicList->setCurrentRow(nextRow);
    startPlayMusic();

    // 如果之前是播放状态，则继续播放
    if (m_isPlaying) {
        m_player->play();
    }
}

void MainWindow::handleModeSlot()
{
    if (m_MODE == ORDER_MODE) {
        m_MODE = RANDOM_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/sui.png"));
    } else if (m_MODE == RANDOM_MODE) {
        m_MODE = CIRCLE_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/xun.png"));
    } else {
        m_MODE = ORDER_MODE;
        ui->modeBtn->setIcon(QIcon(":/icon/shun.png"));
    }
}

void MainWindow::handlePlaySlot()
{
    if (m_player->playbackState() == QMediaPlayer::PlayingState) {
        m_player->pause();
    } else {
        // 如果没有媒体，则先加载第一个
        if (m_player->mediaStatus() == QMediaPlayer::NoMedia && ui->musicList->count() > 0) {
            startPlayMusic();
        }
        m_player->play();
    }
}

void MainWindow::setButtonStyle(QPushButton *button, const QString& filename)
{
    // 设置大小策略为Fixed，防止布局管理器调整
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // 强制设置固定大小
    button->setFixedSize(50, 50);

    // 显式设置图标大小，不依赖按钮宽度
    button->setIconSize(QSize(50, 50));

    // 设置图标和样式
    button->setIcon(QIcon(filename));
    button->setStyleSheet("background-color:transparent");

    // 调试输出（可在测试后移除）
    qDebug() << "Button" << button->objectName()
             << "size:" << button->size()
             << "icon size:" << button->iconSize();
}

void MainWindow::loadAppointMusicDir(const QString &filepath)
{
    QDir dir(filepath);
    if (!dir.exists()) {
        QMessageBox::warning(this, "文件夹", "文件夹打开失败");
        return;
    }

    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    for (auto &element : fileList) {
        if (element.suffix() == "mp3") {
            ui->musicList->addItem(element.baseName());
        }
    }

    if (ui->musicList->count() > 0) {
        ui->musicList->setCurrentRow(0);
    }
}

// 进度条拖动开始
void MainWindow::on_progressBar_sliderPressed()
{
    m_isDraggingProgress = true;
    m_wasPlayingBeforeDrag = m_isPlaying;

    // 如果正在播放，暂时暂停以避免进度冲突
    if (m_wasPlayingBeforeDrag) {
        m_player->pause();
    }
}

// 进度条拖动结束
void MainWindow::on_progressBar_sliderReleased()
{
    m_isDraggingProgress = false;

    // 更新播放位置
    m_player->setPosition(ui->progressBar->value());

    // 恢复原来的播放状态
    if (m_wasPlayingBeforeDrag) {
        m_player->play();
    }
}

// 进度条拖动中
void MainWindow::on_progressBar_sliderMoved(int position)
{
    if (m_isDraggingProgress) {
        m_player->setPosition(position);
    }
}

// 更新播放按钮图标
void MainWindow::updatePlayButtonIcon()
{
    if (m_isPlaying) {
        ui->playBtn->setIcon(QIcon(":/icon/pause.png"));
    } else {
        ui->playBtn->setIcon(QIcon(":/icon/play.png"));
    }
}
