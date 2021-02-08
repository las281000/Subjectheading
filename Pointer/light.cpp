#include "light.h"
#include <QTextCharFormat>

Light::Light(QTextDocument* parent) : BaseClass(parent)
{
    // Устанавливаем цвет подсветки
    m_format.setBackground(QColor(121,232,219));
    t = 0;
}

void Light::highlightBlock(const QString& text)
{
    // С помощью регулярного выражения находим все совпадения
    QRegularExpressionMatchIterator matchIterator = m_pattern.globalMatch(text);
    while (matchIterator.hasNext())
    {
        // Подсвечиваем все совпадения

        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), m_format);
        t++;
    }
    emit setMessageText(t);
}

void Light::searchStr(const QString &str)
{
    // Устанавливаем текст в виде регулярного выражения
    m_pattern = QRegularExpression(str);
    rehighlight(); // Перезапускаем подсветку
}
