#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "boardgenerator.h"
#include <QTableWidget>
#include <QStandardItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void generetingBoard();

public slots:
    void playSlot();
    void ruleSlot();
    void aboutSlot();
    void exitSlot();
    void checkSlot();
    void newGameSlot();


private:
    QLabel *m_slotLabel = new QLabel();
    QHBoxLayout *m_allLayout = new QHBoxLayout();
    QVBoxLayout *m_menuLayout = new QVBoxLayout();
    QLabel *m_wellcomeLabel = new QLabel();
    QLabel *m_URLLabel = new QLabel();
    QVBoxLayout *m_wellcomeLayout = new QVBoxLayout();
    QPushButton *m_play = new QPushButton();
    QPushButton *m_rules = new QPushButton();
    QPushButton *m_aboutMe = new QPushButton();
    QPushButton *m_exit = new QPushButton();
    QVBoxLayout *m_buttosLayout = new QVBoxLayout();
    QWidget *m_window = new QWidget();
    QFont m_font;
    QString m_color;

    QPushButton *m_checkButton = new QPushButton();
    QVBoxLayout *m_playSlotLayout = new QVBoxLayout();
    QLabel *m_header = new QLabel();
    QWidget *m_playSlotLabel = new QWidget();
    QHBoxLayout *m_footer = new QHBoxLayout();
    QPushButton *m_newGame = new QPushButton();

    QTableView *m_boardGrid = new QTableView();
    QStandardItem *m_tableItems = new QStandardItem[81];
    QStandardItemModel *m_tableItemsModel = new QStandardItemModel(9,9);

    int m_board[9][9];
    int m_boardForGame[9][9];
};

#endif // MAINWINDOW_H
