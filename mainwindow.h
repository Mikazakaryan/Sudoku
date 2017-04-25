#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "boardgenerator.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void genereting_board();

public slots:
    void play_slot();
    void rule_slot();
    void about_slot();
    void exit_slot();
    void check_slot();
    void new_game_slot();


private:
    QLabel *m_slot_label = new QLabel();
    QHBoxLayout *m_all_layout = new QHBoxLayout();
    QVBoxLayout *m_menu_layout = new QVBoxLayout();
    QLabel *m_wellcome_label = new QLabel();
    QLabel *m_URL_label = new QLabel();
    QVBoxLayout *m_wellcome_layout = new QVBoxLayout();
    QPushButton *m_play = new QPushButton();
    QPushButton *m_rules = new QPushButton();
    QPushButton *m_about_me = new QPushButton();
    QPushButton *m_exit = new QPushButton();
    QVBoxLayout *m_buttos_layout = new QVBoxLayout();
    QWidget *m_window = new QWidget();
    QFont m_font;
    QString m_color;

    QPushButton *m_check_button = new QPushButton();
    QGridLayout *m_board_grid = new QGridLayout();
    QVBoxLayout *m_play_slot_layout = new QVBoxLayout();
    QLabel *m_header = new QLabel();
    QWidget *m_play_slot_label = new QWidget();
    QHBoxLayout *m_footer = new QHBoxLayout();
    QPushButton *m_new_game = new QPushButton();

    int m_board[9][9];
    int m_board_for_game[9][9];
    QVector <int> m_temp;


};

#endif // MAINWINDOW_H
