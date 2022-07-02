#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>
#include <QtGui>
#include <ctime>
#include <QLineEdit>
#include <QDebug>
#include <QRect>
#include <QString>
#include <random>

MainWindow::MainWindow(QWidget *parent) //생성자
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    second = 30; //타이머에 나타날 남은 시간
    score = 0; //점수
    count = 0; //나타난 단어의 수
    ui->setupUi(this);

    timer = new QTimer(this); //타이머 동적할당
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime())); //타이머 connect
    timer->start(1000); //타이머 전환 단위 = 1초

}

MainWindow::~MainWindow() //소멸자
{
    delete ui;
}

void MainWindow::stopTimer(){ //타이머를 멈추고 메세지를 ㄸㅢ우는 함수
    if(second <=0){  //남은 시간이 0초 이하일 ㄸㅐ
        second = 0; // 0으로 전환
        ui->lcdNumber->display(second); //0으로 전환하여 디스플레이에 출력
        //timer->stop(); //타이머 종료
        QString msgnum = QString::number(ui->lcdNumber_2->intValue());
        QString msg ;
                msg += "Your point is ";
                msg += msgnum;
                msg += ". Continue?";


        QMessageBox::StandardButton reply //메세지 팝업

                = QMessageBox::question(this, "TimeOut", msg, QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){ //Yes인 경우, 시간, 점수, 단어 초기화
           second=30;
           ui->lcdNumber->display(second);//초 표현
           score=0;
           count=0;
           ui->lcdNumber_2->display(score);//점수표현
           ui->word1->setText("");//텍스트 초기 설정 = 빈칸
           ui->word1->move(rand()%700,100);//랜덤으로 ㅇㅟ치선정
           ui->word2->setText("");
           ui->word2->move(rand()%700,100);
           ui->word3->setText("");
           ui->word3->move(rand()%700,100);
           ui->word4->setText("");
           ui->word4->move(rand()%700,100);
           ui->word5->setText("");
           ui->word5->move(rand()%700,100);
           ui->word6->setText("");
           ui->word6->move(rand()%700,100);

    }
    else{
        delete timer;
        QApplication::quit();
    }
    }
}

void MainWindow::displaytime(){
     ui->lcdNumber->display(second);
    second--; //타이머 1초ㅆㅣㄱ 내리기
    if(second<0){
        stopTimer();//타이머 시간 설정 및 메세지 출력 함수
    }
    count++;//count 1 증가

    if(ui->word1->text()!="") {//단어가 있을 시, 1초마다 y좌표 20ㅆㅣㄱ 추가
    ui->word1->move(ui->word1->x(),ui->word1->y()+20);
        for(int i = 0; i<10; i++){
            if(ui->word1->text()==crazy_words[i]&&ui->word1->y()<300){ //이ㄸㅐ, 단어가 어려운 단어이고, y 좌표가 300 미만인 경우
                ui->word1->move(ui->word1->x(),ui->word1->y()+10);//10을 추가로 추가(1.5배 ㅂㅐ속을 위함)
           }
       }
    }
    if(ui->word2->text()!="") {//word1과 마찬가지로 다른 단어들도 동일 처리
    ui->word2->move(ui->word2->x(),ui->word2->y()+20);
    for(int i = 0; i<10; i++){
        if(ui->word2->text()==crazy_words[i]&&ui->word2->y()<300){
            ui->word2->move(ui->word2->x(),ui->word2->y()+10);
       }
   }
    }
    if(ui->word3->text()!="") {
    ui->word3->move(ui->word3->x(),ui->word3->y()+20);
    for(int i = 0; i<10; i++){
        if(ui->word3->text()==crazy_words[i]&&ui->word3->y()<300){
            ui->word3->move(ui->word3->x(),ui->word3->y()+10);
       }
        }
    }
    if(ui->word4->text()!="") {
    ui->word4->move(ui->word4->x(),ui->word4->y()+20);
    for(int i = 0; i<10; i++){
        if(ui->word4->text()==crazy_words[i]&&ui->word4->y()<300){
            ui->word4->move(ui->word4->x(),ui->word4->y()+10);
       }
    }
    }
    if(ui->word5->text()!="") {
    ui->word5->move(ui->word5->x(),ui->word5->y()+20);
    for(int i = 0; i<10; i++){
        if(ui->word5->text()==crazy_words[i]&&ui->word5->y()<300){
            ui->word5->move(ui->word5->x(),ui->word5->y()+10);
       }
    }
    }
    if(ui->word6->text()!="") {
    ui->word6->move(ui->word6->x(),ui->word6->y()+20);
    for(int i = 0; i<10; i++){
        if(ui->word6->text()==crazy_words[i]&&ui->word6->y()<300){
            ui->word6->move(ui->word6->x(),ui->word6->y()+10);
       }
    }
    }




    for (;ui->word1->text()==""||ui->word2->text()==""||ui->word3->text()==""||ui->word4->text()==""||ui->word5->text()==""||ui->word6->text()=="";) {
        if(ui->word1->text()=="") {//word1이 빈칸인 경우
        QString temp;
        if(count%5!=0){
            temp = easy_words[rand()%30];//count가 5의 배수가 ㅇㅏ닌 경우 (80%의 경우) easyword에서 단어 입력
            ui->word1->setStyleSheet("QLabel{color : black;}");//색상은 블랙
        }
        else{
            temp = crazy_words[rand()%10];//count가 5의 배수인 경우(20%의 경우) crazyword에서 단어 입력
            ui->word1->setStyleSheet("QLabel{color : red;}");//색상은 ㅃㅏㄹ강
        }
        ui->word1->move(rand()%700,100);//초기위치로 ㅇㅣ동
        ui->word1->setText(temp); // 단어 출력
        count++; //count 증가
        ui->word1->show();
        break;
        }
        if(ui->word2->text()=="") {//word1과 마찬가지로 처리(word6ㄲㅏ지 모두)
            ui->word2->move(rand()%700,100);
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word2->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word2->setStyleSheet("QLabel{color : red;}");
            }
        ui->word2->setText(temp); // easy_word 중 랜덤으로 ㄸㅢ우기
        count++;
        ui->word2->show();
        break;
        }
        if(ui->word3->text()=="") {
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word3->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word3->setStyleSheet("QLabel{color : red;}");
            }
        ui->word3->move(rand()%700,100);
        ui->word3->setText(temp); // easy_word 중 랜덤으로 ㄸㅢ우기
        count++;
        ui->word3->show();
        break;
        }
        if(ui->word4->text()=="") {
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word4->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word4->setStyleSheet("QLabel{color : red;}");
            }
            ui->word4->move(rand()%700,100);
        ui->word4->setText(temp); // easy_word 중 랜덤으로 ㄸㅢ우기
        count++;
        ui->word4->show();
        break;
        }
        if(ui->word5->text()=="") {
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word5->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word5->setStyleSheet("QLabel{color : red;}");
            }
            ui->word5->move(rand()%700,100);
        ui->word5->setText(temp); // easy_word 중 랜덤으로 ㄸㅢ우기
        count++;
        ui->word5->show();
        break;
        }
        if(ui->word6->text()=="") {
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word6->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word6->setStyleSheet("QLabel{color : red;}");
            }
            ui->word6->move(rand()%700,100);
        ui->word6->setText(temp); // easy_word 중 랜덤으로 ㄸㅢ우기
        count++;
        ui->word6->show();
        break;
        }
    }


        if(ui->word1->y()>=500) {//word1이 y축 아래(단어 입력 위치 바로 ㅇㅟ)ㄲㅏ지 도달했을 ㄸㅐ
            second-=3;//시간 3초 감소
            ui->lcdNumber->display(second);//시간 감소 표현
            ui->word1->setText("");//단어 내용 삭제
        }
        if(ui->word2->y()>=500) {//word1과 동일하게 처리(word6ㄲㅏ지)
            second-=3;
            ui->lcdNumber->display(second);
            ui->word2->setText("");
        }
        if(ui->word3->y()>=500) {
            second-=3;
            ui->lcdNumber->display(second);
            ui->word3->setText("");
        }
        if(ui->word4->y()>=500) {
            second-=3;
            ui->lcdNumber->display(second);
            ui->word4->setText("");
        }
        if(ui->word5->y()>=500) {
            second-=3;
            ui->lcdNumber->display(second);
            ui->word5->setText("");
        }
        if(ui->word6->y()>=500) {
            second-=3;
            ui->lcdNumber->display(second);
            ui->word6->setText("");
        }




}

void MainWindow::on_lineEdit_returnPressed()
{
    QString _return = ui->lineEdit->text();//입력받은 문자열 저장
    int i=0;
    while (i<6) {
        if(ui->word1->text()==_return) {//입력받은 문자열이 word1과 동일한 경우
            score+=10;//점수10점 추가
            for(int i=0; i<10; i++){//문자가 crazyword인 경우
                if(ui->word1->text()==crazy_words[i]){
                    score+=5;//점수 5점 추가로 추가
                }
            }
            ui->lcdNumber_2->display(score);//점수 출력
            QString temp;//새롭게 무작위 단어 입력 받음
            if(count%5!=0){
                temp = easy_words[rand()%30];//쉬운 단어 생성
                ui->word1->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];//어려운 단어 생성
                ui->word1->setStyleSheet("QLabel{color : red;}");
            }
        ui->word1->setText(temp);//단어 출력
        count++;//count 추가
        ui->word1->move(rand()%700,100);//단어 이동
        break;
        }
        if(ui->word2->text()==_return) {//word1과 동일하게 수행(word6ㄲㅏ지)
            score+=10;
            for(int i=0; i<10; i++){
                if(ui->word2->text()==crazy_words[i]){
                    score+=5;
                }
            }
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word2->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word2->setStyleSheet("QLabel{color : red;}");
            }
            ui->lcdNumber_2->display(score);
        ui->word2->setText(temp);
        count++;
        ui->word2->move(rand()%700,100);
        break;
        }
        if(ui->word3->text()==_return) {
            score+=10;
            for(int i=0; i<10; i++){
                if(ui->word3->text()==crazy_words[i]){
                    score+=5;
                }
            }
            ui->lcdNumber_2->display(score);
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word3->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word3->setStyleSheet("QLabel{color : red;}");
            }
        ui->word3->setText(temp);
        count++;
        ui->word3->move(rand()%700,100);
        break;
        }
        if(ui->word4->text()==_return) {
            score+=10;
            for(int i=0; i<10; i++){
                if(ui->word4->text()==crazy_words[i]){
                    score+=5;
                }
            }
            ui->lcdNumber_2->display(score);
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word4->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word4->setStyleSheet("QLabel{color : red;}");
            }
        ui->word4->setText(temp);
        count++;
        ui->word4->move(rand()%700,100);
        break;
        }
        if(ui->word5->text()==_return) {
            score+=10;
            for(int i=0; i<10; i++){
                if(ui->word5->text()==crazy_words[i]){
                    score+=5;
                }
            }
            ui->lcdNumber_2->display(score);
            QString temp;
            if(count%5!=0){
                temp = easy_words[rand()%30];
                ui->word5->setStyleSheet("QLabel{color : black;}");
            }
            else{
                temp = crazy_words[rand()%10];
                ui->word5->setStyleSheet("QLabel{color : red;}");
            }
        ui->word5->setText(temp);
        count++;
        ui->word5->move(rand()%700,100);
        break;
        }
        if(ui->word6->text()==_return) {
        score+=10;
        for(int i=0; i<10; i++){
            if(ui->word6->text()==crazy_words[i]){
                score+=5;
            }
        }
        QString temp;
        if(count%5!=0){
            temp = easy_words[rand()%30];
            ui->word6->setStyleSheet("QLabel{color : black;}");
        }
        else{
            temp = crazy_words[rand()%10];
            ui->word6->setStyleSheet("QLabel{color : red;}");
        }
        ui->word6->setText(temp);
        count++;
        ui->word6->move(rand()%700,100);
        break;
        }
        i++;
    }

    ui->lineEdit->setText("");//lineEdit 비우기
}

