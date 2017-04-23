#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QString>
#include <rules_p.h>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void play_slot();
    void rules_slot();
    void about_me_slot();
    void exit_slot();

private:
    QLabel *m_wellcome_label = new QLabel();
    QLabel *m_URL_label = new QLabel();
    QWidget *m_window = new QWidget();
    QPushButton *m_play = new QPushButton();
    QPushButton *m_rules = new QPushButton();
    QPushButton *m_about_me = new QPushButton();
    QPushButton *m_exit = new QPushButton();
    QVBoxLayout *m_buttos_layout = new QVBoxLayout;
    QHBoxLayout *m_wellcome_layout = new QHBoxLayout;
    QVBoxLayout *m_layout = new QVBoxLayout;
    QFont m_font;
    QString m_color;
};

#endif // MAINWINDOW_H
