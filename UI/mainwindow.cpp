#include "mainwindow.h"


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

    connect(m_play, SIGNAL(clicked()), this, SLOT(play_slot()));
    connect(m_rules, SIGNAL(clicked(bool)), this, SLOT(rule_slot()));
    connect(m_about_me, SIGNAL(clicked(bool)), this, SLOT(about_slot()));
    connect(m_exit, SIGNAL(clicked()), this, SLOT(exit_slot()));
    connect(m_back_button, SIGNAL(clicked()), this, SLOT(back_slot()));
}

void MainWindow::back_slot(){

}

void MainWindow::play_slot(){

}

void MainWindow::about_slot(){
    m_back_button->setText("Back");
    m_text_label->setText("I'm a Bachelor's degree student\n"
                          "who want to get max point\n"
                          "for this work");
    m_font.setPointSize(25);
    m_text_label->setFont(m_font);
    m_text_label->setAlignment(Qt::AlignCenter);

    m_text_label->setFixedSize(650,300);

    m_font.setPointSize(20);
    m_font.setBold(false);
    m_back_button->setFont(m_font);

    m_color = "color: black";
    m_back_button->setStyleSheet(m_color);
    m_color = "background-color: gray";
    m_back_button->setStyleSheet(m_color);

    m_about_layout->addWidget(m_back_button);
    m_about_layout->addWidget(m_text_label);
    m_about_layout->addWidget(m_exit);

    m_about_window->setLayout(m_about_layout);

    setCentralWidget(m_about_window);
}

void MainWindow::rule_slot(){
    m_back_button->setText("Back");
    m_text_label->setText("A standard Sudoku puzzle consists of a grid of 9 blocks.\n"
                        "Each block contains 9 boxes \n"
                        "arranged in 3 rows and 3 columns."
                        "\n· There is only one valid solution\n"
                        "to each Sudoku puzzle.\n"
                        "The only way the puzzle can be considered solved\n"
                        "correctly is when all 81 boxes contain numbers and\n"
                        "the other Sudoku rules have been followed.\n"
                        "· When you start a game of Sudoku,\n"
                        "some blocks will be pre-filled for you.\n"
                        "You cannot change these numbers in the course of the game.\n"
                        "· Each column must contain all of the numbers 1 through 9 an\n"
                        "no two numbers in the same column of a Sudoku puzzle can be the same.\n"
                        "· Each row must contain all of the numbers 1 through 9 and\n"
                        "no two numbers in the same row of a Sudoku puzzle can be the same.\n"
                        "· Each block must contain all of the numbers 1 through 9 and\n"
                        "no two numbers in the same block of a Sudoku puzzle can be the same.");
    m_font.setPointSize(10);
    m_text_label->setFont(m_font);
    m_text_label->setAlignment(Qt::AlignCenter);

    m_text_label->setFixedSize(650,300);

    m_font.setPointSize(20);
    m_font.setBold(false);
    m_back_button->setFont(m_font);

    m_color = "color: black";
    m_back_button->setStyleSheet(m_color);
    m_color = "background-color: gray";
    m_back_button->setStyleSheet(m_color);

    m_rules_layout->addWidget(m_back_button);
    m_rules_layout->addWidget(m_text_label);
    m_rules_layout->addWidget(m_exit);

    m_rules_window->setLayout(m_rules_layout);

    setCentralWidget(m_rules_window);
}


void MainWindow::exit_slot(){
    close();
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
    delete m_rules_window;
    delete m_back_button;
    delete m_text_label;
    delete m_rules_layout;
    delete m_about_window;
    delete m_about_layout;
}

