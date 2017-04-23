#include "mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(650,400);

     setCentralWidget(m_window);


    m_wellcome_label->setText("Wellcome to ");
    m_URL_label->setOpenExternalLinks(true);
    m_URL_label->setText("<a href='https://github.com/Mikazakaryan/Sudoku' style=\"color: black;\">MSudoku</a>");

    m_wellcome_layout->addWidget(m_wellcome_label);
    m_wellcome_layout->addWidget(m_URL_label);

    m_wellcome_layout->setAlignment(Qt::AlignCenter);

    m_play->setText("Play");
    m_rules->setText("Rules");
    m_about_me->setText("About");
    m_exit->setText("Exit");

    m_buttos_layout->addWidget(m_play);
    m_buttos_layout->addWidget(m_rules);
    m_buttos_layout->addWidget(m_about_me);
    m_buttos_layout->addWidget(m_exit);

    m_layout->addLayout(m_wellcome_layout);
    m_layout->addLayout(m_buttos_layout);

    m_window->setLayout(m_layout);

    m_font.setPointSize(20);

    m_play->setFont(m_font);
    m_rules->setFont(m_font);
    m_about_me->setFont(m_font);
    m_exit->setFont(m_font);

    m_font.setPointSize(40);
    m_font.setBold(true);

    m_wellcome_label->setFont(m_font);
    m_URL_label->setFont(m_font);

    m_color = "background-color: Orange";
    this->setStyleSheet(m_color);

    m_color = "color: black";
    m_play->setStyleSheet(m_color);
    m_rules->setStyleSheet(m_color);
    m_about_me->setStyleSheet(m_color);
    m_exit->setStyleSheet(m_color);

    m_wellcome_label->setStyleSheet(m_color);
    m_color = "background-color: gray";
    m_play->setStyleSheet(m_color);
    m_rules->setStyleSheet(m_color);
    m_about_me->setStyleSheet(m_color);
    m_exit->setStyleSheet(m_color);





      connect(m_exit, SIGNAL(clicked()), SLOT(quit()));
}


MainWindow::~MainWindow()
{
    delete m_layout;
    delete m_buttos_layout;
    delete m_URL_label;
    delete m_wellcome_label;
    delete m_window;
    delete m_play;
    delete m_rules;
    delete m_about_me;
    delete m_exit;
    delete m_wellcome_layout;
}

