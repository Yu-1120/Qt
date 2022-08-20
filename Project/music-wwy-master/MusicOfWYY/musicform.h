#ifndef MUSICFORM_H
#define MUSICFORM_H

#include <QWidget>

namespace Ui {
class MusicForm;
}

class MusicForm : public QWidget
{
    Q_OBJECT

public:
    explicit MusicForm(QWidget *parent = nullptr);
    ~MusicForm();
    void setMusicName(QString musicName);
    void setMusicAuthor(QString musicAuther);
    void setMusicPicture(QString url);

private:
    Ui::MusicForm *ui;
};

#endif // MUSICFORM_H
