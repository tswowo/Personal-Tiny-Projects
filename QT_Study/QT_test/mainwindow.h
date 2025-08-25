#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum PLAYMODE{
    ORDER_MODE,
    RANDOM_MODE,
    CIRCLE_MODE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handlePlaySlot();
    void handleModeSlot();
    void handleNextSlot();
    void handlePrevSlot();
    void startPlayMusic();//加载并播放音乐
    void musicListSlot();//展开和收起音乐列表
    void showAnimation(QWidget*window);//显示展开动画
    void closeAnimation(QWidget*window);//显示收起动画
    void handlePositionSlot(int position);//音乐进度
    void handleDurationSlot(int duration);//总时长
    QString formatTime(int milliseconds);//转换为时间
    void updatePlayButtonIcon();
    //切换背景功能
    void initBackground();
    void loadBackgroundImages();
    void switchToNextBackground();

private:
    Ui::MainWindow *ui;
    void setButtonStyle(QPushButton *button,const QString& filename);//设置按钮样式
    void initButton();//初始化按钮
    void setBackGround(const QString& filename);//设置背景
    QMediaPlayer *m_player;//播放器
    QAudioOutput *audioOutput;//音频输出
    void loadAppointMusicDir(const QString &filepath);//加载音乐文件夹
    PLAYMODE m_MODE;//播放模式
    QString m_musicDir;//音乐绝对路径
    bool m_isShowFlag;//列表是否存在
    bool m_isSliderBeingDragged;//标记进度条是否正在被拖动
    bool m_wasPlayingBeforeDrag;//记录拖动前的播放状态
    bool m_isPlaying;  // 明确记录播放状态
    bool m_isDraggingProgress;  // 记录进度条是否正在被拖动
    //用以拖动进度条
    void on_progressBar_sliderMoved(int position);
    void on_progressBar_sliderPressed();
    void on_progressBar_sliderReleased();
    //用于拖动音量条
    void on_volume_slider_valueChanged(int value);
    void updateVolumeDisplay(int volume);
    QList<QString> m_backgroundImages;  // 存储背景图片路径
    int m_currentBackgroundIndex;       // 当前背景索引
};
#endif // MAINWINDOW_H
