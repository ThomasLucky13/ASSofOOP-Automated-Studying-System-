#ifndef TESTMODUL_H
#define TESTMODUL_H

#include <QWidget>

namespace Ui {
class TestModul;
}

class TestModul : public QWidget
{
    Q_OBJECT

public:
    explicit TestModul(QWidget *parent = nullptr);
    ~TestModul();

private:
    Ui::TestModul *ui;
};

#endif // TESTMODUL_H
