﻿#include "selectDialog.h"
#include<QSpacerItem>

selectDialog ::selectDialog (QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    m_stack = new stacked;
    m_btn1 = new QPushButton("one");

    m_btn2 = new QPushButton("开始");
    connect(m_btn2,SIGNAL(clicked(bool)),this,SLOT(accept()));
    m_btn3 = new QPushButton("退出");
    connect(m_btn3,SIGNAL(clicked(bool)),this,SLOT(reject()));
    m_btn4 = new QPushButton("four");
    QHBoxLayout *hLay = new QHBoxLayout();
    //QSpacerItem *spacer = new QSpacerItem(400,200);
    //hLay->addItem(spacer);
        hLay->addStretch(1);
    hLay->addStretch(1);

    hLay->addWidget(m_btn2);
        hLay->addStretch(1);
    hLay->addWidget(m_btn3);
    hLay->addStretch(1);
        hLay->addStretch(1);


    QVBoxLayout *vLay = new QVBoxLayout(this);
    QLabel *tishi = new QLabel("请选择模式");
        tishi->setStyleSheet("QLabel{font:bold 32px; color:blue}");
    QHBoxLayout *hlay2 = new QHBoxLayout;
    hlay2->addStretch(1);
    hlay2->addWidget(tishi);
    hlay2->addStretch(1);

    vLay->addLayout(hlay2);
    vLay->addWidget(m_stack,3);
    vLay->addLayout(hLay,1);
    //填充背景图片
    m_backgroundImage.load(":/board/kaishi");
    setAutoFillBackground(true);
}

selectDialog::~selectDialog()
{
}

//重写resizeEvent函数,实现图片拉伸填充窗口
void selectDialog::resizeEvent(QResizeEvent *event)
{
    //调用父类的resizeEvent,处理
    QWidget::resizeEvent(event);
    QPalette pal(palette());

// 注意下面这一行，就是靠他实现大小拉伸～～～
    pal.setBrush(QPalette::Window,
                QBrush(m_backgroundImage.scaled(size(), Qt::IgnoreAspectRatio,
                        Qt::SmoothTransformation)));
    setPalette(pal);
}

//设置按钮图片,无动作时,鼠标移动到其上时,点击时
#if 0
btn1->setStyleSheet(
            "QPushButton{background-image: url(:/new/prefix1/images/1-1.png);}"
"QPushButton:hover{background-image: url(:/new/prefix1/images/2-1.png);}"
"QPushButton:pressed{background-image: url(:/new/prefix1/images/3-1.png);}");
#endif
