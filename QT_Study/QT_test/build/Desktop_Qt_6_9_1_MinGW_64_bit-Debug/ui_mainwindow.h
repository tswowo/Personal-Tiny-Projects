/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *musicList;
    QWidget *layoutWidget;
    QHBoxLayout *combine;
    QLabel *label_1;
    QSlider *progressBar;
    QLabel *label_2;
    QSlider *volume_slider;
    QLabel *volume;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevBtn;
    QPushButton *playBtn;
    QPushButton *nextBtn;
    QPushButton *modeBtn;
    QPushButton *listBtn;
    QPushButton *changeBgBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(909, 579);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(660, 40, 256, 511));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 400, 591, 31));
        combine = new QHBoxLayout(layoutWidget);
        combine->setObjectName("combine");
        combine->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName("label_1");

        combine->addWidget(label_1);

        progressBar = new QSlider(layoutWidget);
        progressBar->setObjectName("progressBar");
        progressBar->setOrientation(Qt::Orientation::Horizontal);

        combine->addWidget(progressBar);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        combine->addWidget(label_2);

        volume_slider = new QSlider(centralwidget);
        volume_slider->setObjectName("volume_slider");
        volume_slider->setGeometry(QRect(531, 70, 41, 281));
        volume_slider->setOrientation(Qt::Orientation::Vertical);
        volume = new QLabel(centralwidget);
        volume->setObjectName("volume");
        volume->setGeometry(QRect(531, 357, 40, 16));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(102, 482, 281, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prevBtn = new QPushButton(layoutWidget1);
        prevBtn->setObjectName("prevBtn");

        horizontalLayout->addWidget(prevBtn);

        playBtn = new QPushButton(layoutWidget1);
        playBtn->setObjectName("playBtn");

        horizontalLayout->addWidget(playBtn);

        nextBtn = new QPushButton(layoutWidget1);
        nextBtn->setObjectName("nextBtn");

        horizontalLayout->addWidget(nextBtn);

        modeBtn = new QPushButton(layoutWidget1);
        modeBtn->setObjectName("modeBtn");

        horizontalLayout->addWidget(modeBtn);

        listBtn = new QPushButton(layoutWidget1);
        listBtn->setObjectName("listBtn");

        horizontalLayout->addWidget(listBtn);

        changeBgBtn = new QPushButton(layoutWidget1);
        changeBgBtn->setObjectName("changeBgBtn");

        horizontalLayout->addWidget(changeBgBtn);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        volume->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        prevBtn->setText(QString());
        playBtn->setText(QString());
        nextBtn->setText(QString());
        modeBtn->setText(QString());
        listBtn->setText(QString());
        changeBgBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
