#include "widget.h"
#include "ui_widget.h"

#include "qperson.h"
#include <QDebug>

#include <QMetaProperty>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new QPerson("小王",this);
    girl = new QPerson("小红",this);
    boy->setProperty("sex",QString("boy"));
    girl->setProperty("sex",QString("girl"));

    boy->setProperty("score",10);
    girl->setProperty("score",10);
    //qInfo()<<1<<""<<boy->property("score");

    ui->boySpinBox->setProperty("isBoy",true);
    ui->girlSpinBox->setProperty("isBoy",false);

    ui->boySpinBox->setValue(boy->age());
    ui->girlSpinBox->setValue(girl->age());
    connect(boy,SIGNAL(ageChange(quint8)),this,SLOT(do_ageChange(quint8)));
    connect(girl,SIGNAL(ageChange(quint8)),this,SLOT(do_ageChange(quint8)));
    connect(ui->boySpinBox,SIGNAL(valueChanged(int)),this,SLOT(do_spinChange(int)));
    connect(ui->girlSpinBox,SIGNAL(valueChanged(int)),this,SLOT(do_spinChange(int)));

//    int a=0;
// //   qDebug()<<"我";
//    [=]()mutable{
//        qDebug()<<a++;
//    }();
//    qDebug()<<a;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_ageChange(quint8 ageValue)
{

     QPerson *tempPerson=qobject_cast<QPerson*>(sender());
     QString str=QString("%1 ,sex = %2, age = %3")
             .arg(tempPerson->property("name").toString())
             .arg(tempPerson->property("sex").toString())
             .arg(ageValue);
     if(tempPerson->property("sex").toString() == "boy")
         ui->boySpinBox->setValue(ageValue);
     if(tempPerson->property("sex").toString() == "girl")
        ui->girlSpinBox->setValue(ageValue);
     ui->plainTextEdit->appendPlainText(str);
}

void Widget::do_spinChange(int arg)
{
    quint8 argUInt8 = static_cast<quint8>(arg);
    QSpinBox *tempSpinbox = qobject_cast<QSpinBox*>(sender());
    if(tempSpinbox->property("isBoy").toBool()){
        boy->setAge(argUInt8);
    }else {
        girl->setAge(argUInt8);
    }
}



void Widget::on_clear_clicked()
{
    ui->plainTextEdit->clear();
}

void Widget::on_addBoyAge_clicked()
{
    boy->inoAge();
}

void Widget::on_addGirlAge_clicked()
{
    girl->inoAge();
}

void Widget::on_showMeta_clicked()
{
    boy->setProperty("sex","boy");
   const QMetaObject *meta=boy->metaObject();
   ui->plainTextEdit->appendPlainText(QString("类型名称：%1").arg(meta->className()));
   ui->plainTextEdit->appendPlainText("属性：");



   for(int i = meta->propertyOffset(); i < meta->propertyCount();i++){
       const char * proName = meta->property(i).name();
       QString typeName = meta->property(i).typeName();

      QString str = QString("%1 :%2").arg(proName).arg(boy->property(proName).toString());


       ui->plainTextEdit->appendPlainText(str);
   }

}

void Widget::on_qMessage_clicked()
{
    QMessageBox::about(this, "about",  "这是一个简单的消息提示框!!!");
       QMessageBox::critical(this, "critical", "这是一个错误对话框-critical...");
       int ret = QMessageBox::question(this, "question",
                "你要保存修改的文件内容吗???",
                 QMessageBox::Save|QMessageBox::Cancel,
                 QMessageBox::Cancel);
       if(ret == QMessageBox::Save)
       {
           QMessageBox::information(this, "information", "恭喜你保存成功了, o(*￣︶￣*)o!!!");
       }
       else if(ret == QMessageBox::Cancel)
       {
           QMessageBox::warning(this, "warning", "你放弃了保存, ┭┮﹏┭┮ !!!");
       }



}

void Widget::on_qFile_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "打开目录", "/");
        QMessageBox::information(this, "打开目录", "您选择的目录是: " + dirName);

}

void Widget::on_qFont_clicked()
{
#if 0
    // 方式1
    bool ok;
    QFont ft = QFontDialog::getFont(
                &ok, QFont("微软雅黑", 12, QFont::Bold), this, "选择字体");
    qDebug() << "ok value is: " << ok;
#else
    // 方式2
    QFont ft = QFontDialog::getFont(NULL);
#endif
    // 将选择的字体设置给当前窗口对象
    this->setFont(ft);


}

void Widget::on_qInput_clicked()
{
#if 0
    int ret = QInputDialog::getInt(this, "年龄", "您的当前年龄: ", 10, 1, 100, 2);
    QMessageBox::information(this, "年龄", "您的当前年龄: " + QString::number(ret));
#else
       QStringList items1;
        items1 << "苹果" << "橙子" << "橘子" << "葡萄" << "香蕉" << "哈密瓜";
        QStringList items2;
         items2<< "A" << "B" << "C"<< "D" << "E" << "F";
        QString item = QInputDialog::getItem(this, "请选择你喜欢的水果", "你最喜欢的水果:", items1,1, false);
        QMessageBox::information(this, "水果", "您最喜欢的水果是: " + item);

#endif

}
