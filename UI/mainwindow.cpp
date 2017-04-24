#include "mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(1700,1000);

    m_slot_label->setFixedSize(0,0);

    m_all_layout->addLayout(m_menu_layout);
    m_all_layout->addWidget(m_slot_label);

    m_wellcome_label->setText("Wellcome to");
    m_URL_label->setOpenExternalLinks(true);
    m_URL_label->setText("<a href='https://github.com/Mikazakaryan/Sudoku' style=\"color: black;\">MSudoku</a>");

    m_wellcome_layout->addWidget(m_wellcome_label);
    m_wellcome_layout->addWidget(m_URL_label);

    m_wellcome_label->setAlignment(Qt::AlignBottom);
    m_URL_label->setAlignment(Qt::AlignHCenter);

    m_wellcome_layout->setAlignment(Qt::AlignHCenter);

    m_play->setText("Play");
    m_rules->setText("Rules");
    m_about_me->setText("About");
    m_exit->setText("Exit");

    m_buttos_layout->addWidget(m_play);
    m_buttos_layout->addWidget(m_rules);
    m_buttos_layout->addWidget(m_about_me);
    m_buttos_layout->addWidget(m_exit);

    m_menu_layout->addLayout(m_wellcome_layout);
    m_menu_layout->addLayout(m_buttos_layout);

    m_window->setLayout(m_all_layout);

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

    setCentralWidget(m_window);

    connect(m_play, SIGNAL(clicked()), this, SLOT(play_slot()));
    connect(m_rules, SIGNAL(clicked()), this, SLOT(rule_slot()));
    connect(m_about_me, SIGNAL(clicked()), this, SLOT(about_slot()));
    connect(m_exit, SIGNAL(clicked()), this, SLOT(exit_slot()));
}

void MainWindow::play_slot(){
    m_slot_label->clear();
    m_slot_label->setFixedSize(900,1000);

    m_font.setPointSize(20);
    m_check_button->setFont(m_font);
    m_color = "background-color: gray";
    m_check_button->setStyleSheet(m_color);

    m_check_button->setText("Check");

    m_check_button->setFixedWidth(900);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(true){
                m_board_grid->addWidget(new QLabel(QString::number(9*i+j)),i,j);
            }else{

            }
        }
    }

    m_play_slot_layout->addLayout(m_board_grid);
    m_play_slot_layout->addWidget(m_check_button);

    m_slot_label->setLayout(m_play_slot_layout);
}

void MainWindow::rule_slot(){
    m_slot_label->setText("A standard Sudoku puzzle consists of a grid of 9 blocks.\n"
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
                        "· Each column must contain all of the numbers 1 through 9 and\n"
                        "no two numbers in the same column of a Sudoku puzzle can be the same.\n"
                        "· Each row must contain all of the numbers 1 through 9 and\n"
                        "no two numbers in the same row of a Sudoku puzzle can be the same.\n"
                        "· Each block must contain all of the numbers 1 through 9 and\n"
                        "no two numbers in the same block of a Sudoku puzzle can be the same.");

    m_font.setPointSize(15);
    m_slot_label->setFont(m_font);

    m_slot_label->setAlignment(Qt::AlignCenter);

    m_slot_label->setFixedSize(900,1000);
}

void MainWindow::about_slot(){
    m_slot_label->setText("I'm a Bachelor's degree student\n"
                          "who want to get max point\n"
                          "for this work");
    m_font.setPointSize(25);
    m_slot_label->setFont(m_font);
    m_slot_label->setAlignment(Qt::AlignCenter);

    m_slot_label->setFixedSize(900,1000);
}

void MainWindow::exit_slot(){
    close();
}

MainWindow::~MainWindow()
{
    delete m_all_layout;
    delete m_menu_layout;
    delete m_wellcome_label;
    delete m_URL_label;
    delete m_wellcome_layout;
    delete m_play;
    delete m_rules;
    delete m_about_me;
    delete m_exit;
    delete m_buttos_layout;
    delete m_window;
}
