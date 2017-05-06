#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(800,900);

    m_slotLabel->setFixedSize(0,0);

    m_allLayout->addLayout(m_menuLayout);

    m_wellcomeLabel->setText("Wellcome to");
    m_URLLabel->setOpenExternalLinks(true);
    m_URLLabel->setText("<a href='https://github.com/Mikazakaryan/Sudoku' style=\"color: black;\">MSudoku</a>");

    m_wellcomeLayout->addWidget(m_wellcomeLabel);
    m_wellcomeLayout->addWidget(m_URLLabel);

    m_wellcomeLabel->setAlignment(Qt::AlignBottom);
    m_URLLabel->setAlignment(Qt::AlignHCenter);

    m_wellcomeLayout->setAlignment(Qt::AlignHCenter);
    m_slotLabel->setLayout(m_wellcomeLayout);

    m_play->setText("Play");
    m_rules->setText("Rules");
    m_aboutMe->setText("About");
    m_exit->setText("Exit");

    m_buttosLayout->addWidget(m_play);
    m_buttosLayout->addWidget(m_rules);
    m_buttosLayout->addWidget(m_aboutMe);
    m_buttosLayout->addWidget(m_exit);

    m_slotLabel->setFixedSize(800,900);

    m_menuLayout->addWidget(m_slotLabel);
    m_menuLayout->addLayout(m_buttosLayout);

    m_window->setLayout(m_allLayout);

    m_font.setPointSize(20);

    m_play->setFont(m_font);
    m_rules->setFont(m_font);
    m_aboutMe->setFont(m_font);
    m_exit->setFont(m_font);

    m_font.setPointSize(40);
    m_font.setBold(true);

    m_wellcomeLabel->setFont(m_font);
    m_URLLabel->setFont(m_font);

    m_color = "background-color: Orange";
    this->setStyleSheet(m_color);

    m_color = "color: black";
    m_play->setStyleSheet(m_color);
    m_rules->setStyleSheet(m_color);
    m_aboutMe->setStyleSheet(m_color);
    m_exit->setStyleSheet(m_color);
    m_wellcomeLabel->setStyleSheet(m_color);

    m_color = "background-color: gray";
    m_play->setStyleSheet(m_color);
    m_rules->setStyleSheet(m_color);
    m_aboutMe->setStyleSheet(m_color);
    m_exit->setStyleSheet(m_color);

    setCentralWidget(m_window);

    connect(m_play, SIGNAL(clicked()), this, SLOT(playSlot()));
    connect(m_rules, SIGNAL(clicked()), this, SLOT(ruleSlot()));
    connect(m_aboutMe, SIGNAL(clicked()), this, SLOT(aboutSlot()));
    connect(m_exit, SIGNAL(clicked()), this, SLOT(exitSlot()));
}

void MainWindow::playSlot(){
    m_font.setBold(false);
    this->setCentralWidget(m_playSlotLabel);

    m_playSlotLabel->setLayout(m_playSlotLayout);
    m_font.setPointSize(20);
    m_header->setText("Y o u   c a n   d o   i t");
    m_color = "color : blue";
    m_header->setStyleSheet(m_color);
    m_header->setFont(m_font);
    m_header->setFixedSize(780,50);
    m_header->setAlignment(Qt::AlignHCenter);
    m_checkButton->setFixedSize(780,50);
    m_exit->setFixedSize(350,50);

    m_font.setPointSize(20);
    m_checkButton->setFont(m_font);
    m_color = "background-color: gray";
    m_checkButton->setStyleSheet(m_color);

    m_checkButton->setText("Check");

    m_checkButton->setFixedSize(780,50);

    m_newGame->setStyleSheet(m_color);

    m_newGame->setText("New Game");
    m_newGame->setFont(m_font);
    m_newGame->setFixedSize(350,50);

    m_playSlotLayout->addWidget(m_header);
    m_playSlotLayout->addWidget(m_checkButton);
    m_playSlotLayout->addWidget(m_boardGrid);
    m_boardGrid->setModel(m_tableItemsModel);
    m_footer->addWidget(m_newGame);
    m_footer->addWidget(m_exit);
    m_playSlotLayout->addLayout(m_footer);

    m_playSlotLayout->setAlignment(Qt::AlignCenter);

    for (int i = 0; i < 9; ++i) {
        m_boardGrid->setColumnWidth(i,78);
        m_boardGrid->setRowHeight(i,78);
    }

    generetingBoard();

    connect(m_checkButton, SIGNAL(clicked()), this, SLOT(checkSlot()));

    connect(m_newGame, SIGNAL(clicked()), this, SLOT(newGameSlot()));
}

void MainWindow::ruleSlot(){
    m_wellcomeLabel->setText("");
    m_URLLabel->setOpenExternalLinks(false);
    m_URLLabel->setText("");
    m_slotLabel->setText("A standard Sudoku puzzle consists of a grid of 9 blocks.\n"
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
    m_slotLabel->setFont(m_font);

    m_slotLabel->setAlignment(Qt::AlignCenter);

    m_slotLabel->setFixedSize(800,900);
}

void MainWindow::aboutSlot(){
    m_wellcomeLabel->setText("");
    m_URLLabel->setOpenExternalLinks(false);
    m_URLLabel->setText("");
    m_slotLabel->setText("I'm a Bachelor's degree student\n"
                          "who want to get max point\n"
                          "for this work");
    m_font.setPointSize(25);
    m_slotLabel->setFont(m_font);
    m_slotLabel->setAlignment(Qt::AlignCenter);

    m_slotLabel->setFixedSize(800,900);

}

void MainWindow::exitSlot(){
    close();
}

void MainWindow::newGameSlot(){

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_tableItems[9*i+j].setText("");
            m_tableItems[9*i+j].setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        }
    }
    generetingBoard();
}

void MainWindow::checkSlot(){
    bool gameStatus = true;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(m_board[i][j] != m_boardForGame[i][j]){
                gameStatus = false;
                m_tableItems[9*i+j].setForeground(Qt::red);
            }else{
                if(m_tableItems[9*i+j].foreground() != Qt::black){
                    m_tableItems[9*i+j].setForeground(Qt::green);
                    m_tableItems[9*i+j].setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
                }
            }
        }
    }
    if(gameStatus){
        m_color = "color: green";
        m_header->setStyleSheet(m_color);
        m_header->setText("C o n g r a t u l a t i o n s");
    }else{
        m_color = "color: red";
        m_header->setStyleSheet(m_color);
        m_header->setText("T r y   h a r d e r");
    }
}

void MainWindow::generetingBoard(){
    boardGenerator boardGenerator;

    changeable = false;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_board[i][j] = boardGenerator.getBoard(i,j);
        }
    }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                m_boardForGame[i][j] = boardGenerator.getBoardForGame(i,j);
            }
        }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            m_font.setPointSize(40);
            m_tableItems[9*i+j].setFont(m_font);

            m_tableItems[9*i+j].setTextAlignment(Qt::AlignCenter);
            m_tableItemsModel->setItem(i,j,&m_tableItems[9*i+j]);

            if(m_boardForGame[i][j] != 0){
                m_tableItems[9*i+j].setForeground(Qt::black);

                m_tableItems[9*i+j].setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

                m_tableItems[9*i+j].setText(QString::number(m_boardForGame[i][j]));
            }else{
                m_tableItems[9*i+j].setForeground(Qt::blue);
            }
        }
    }
    changeable = true;
    connect(m_tableItemsModel, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(itemChanged(QStandardItem*)));
}

void MainWindow::itemChanged(QStandardItem* changedItem)
{
    if(changeable){
        int row = changedItem->row();
        int col = changedItem->column();
        int value = m_tableItems[9*row+col].text().toInt();
        if(value != m_boardForGame[row][col]){
            m_boardForGame[row][col] = value;
            m_tableItems[9*row+col].setForeground(Qt::blue);
        }
    }
}

MainWindow::~MainWindow()
{
    delete m_tableItems;
    delete m_tableItemsModel;
    delete m_header;
    delete m_checkButton;
    delete m_exit;
    delete m_newGame;
    delete m_boardGrid;
    delete m_footer;

    delete m_playSlotLayout;

    delete m_play;
    delete m_rules;
    delete m_aboutMe;

    delete m_playSlotLabel;
    delete m_buttosLayout;

    delete m_URLLabel;
    delete m_wellcomeLabel;

    delete m_wellcomeLayout;

    delete m_menuLayout;
    delete m_slotLabel;

    delete m_allLayout;

    delete m_window;
}
