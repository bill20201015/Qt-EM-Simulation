#ifndef INPUTLINE_H
#define INPUTLINE_H

#include <QWidget>

namespace Ui {
class InputLine;
}

class InputLine : public QWidget
{
    Q_OBJECT

public:
    explicit InputLine(QWidget *parent = nullptr,bool isCombox=true);
    void setText(QString text);
    QString getLine();
    void addComboItem(QString text);
    ~InputLine();
    void hideCombox();

private:
    Ui::InputLine *ui;
};

#endif // INPUTLINE_H
