#ifndef SCALER_H
#define SCALER_H

#include <QObject>
#include <QThreadPool>
#include <QtConcurrent>
#include <QThread>
#include <QMutex>
#include "components/cache/cache.h"
#include "scalerrequest.h"
#include "scalerrunnable.h"
#include "time.h"

class Scaler : public QObject
{
    Q_OBJECT
public:
    explicit Scaler(Cache *_cache, QObject *parent = nullptr);

signals:
    void scalingFinished(QPixmap* result, ScalerRequest request);
    void acceptScalingResult(QImage *image, ScalerRequest req);
    void startBufferedRequest();

public slots:
    void requestScaled(ScalerRequest req);

private slots:
    void onTaskStart(ScalerRequest req);
    void onTaskFinish(QImage* scaled, ScalerRequest req);
    void slotStartBufferedRequest();
    void slotForwardScaledResult(QImage *image, ScalerRequest req);

private:
    QThreadPool *pool;
    ScalerRunnable *runnable;
    bool buffered, running;
    clock_t currentRequestTimestamp;
    ScalerRequest bufferedRequest, startedRequest;

    Cache *cache;

    void startRequest(ScalerRequest req);

    QSemaphore *sem;
};

#endif // SCALER_H
