#ifndef NEWPLAYLIST_H
#define NEWPLAYLIST_H

#include <QDialog>

namespace Ui {
class NewPlaylist;
}

class NewPlaylist : public QDialog
{
    Q_OBJECT

public:
    explicit NewPlaylist(QWidget *parent = nullptr);
    ~NewPlaylist();

signals:
    void playlistCreated(QString name);

private slots:
    void on_create_clicked();

    void on_cancel_clicked();

private:
    Ui::NewPlaylist *ui;
};

#endif // NEWPLAYLIST_H
