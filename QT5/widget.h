#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPerson;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    QPerson *boy;
    QPerson *girl;
private slots:
    void do_ageChange(quint8 ageValue);
    void do_spinChange(int arg);

    void on_addBoyAge_clicked();

    void on_addGirlAge_clicked();
    void on_clear_clicked();

    void on_showMeta_clicked();

    void on_qMessage_clicked();

    void on_qFile_clicked();

    void on_qFont_clicked();

    void on_qInput_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
