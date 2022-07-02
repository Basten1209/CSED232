#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;//타이머
    QTimer *displayTimer;
    QString inputline;
    QString words[6];
    int count;//나타난 단어 ㄱㅐ수
    int second;//남은시간
    int score;//점수
    QString easy_words[30] =  {"명징","직조", "갈증","비행기","나흗날","비둘기",
                               "옹달샘", "줄이다", "거울", "집오리", "물리학", "토마토", "올리브", "은박지",
                               "문지방", "물병", "양치질", "어린이", "집무실", "달빛", "다르다", "부고", "낫",
                               "서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};

    QString crazy_words[10]= {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다",
                              "도톰하다", "넓적부리", "타란티노", "방울토마토", "객체지향수업", "컴퓨터공학과" };

public slots:
    void displaytime();
    void stopTimer();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
