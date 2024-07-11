#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class Bridge : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
//    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER name NOTIFY nameChanged)
    Q_PROPERTY(int age MEMBER age NOTIFY ageChanged)

public:
    explicit Bridge(QObject *parent = nullptr);

//    void setName(const QString &name) {
//        if (name != m_name) {
//            m_name = name;
//            emit nameChanged();
//        }
//    }

//    void setAge(int age) {
//        if (age != m_age) {
//            m_age = age;
//            emit ageChanged();
//        }
//    }
    void run();

signals:
    void nameChanged();
    void ageChanged();
public:
    QString name;
    int age;
};

#endif // BRIDGE_H
