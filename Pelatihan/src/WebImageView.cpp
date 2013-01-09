/*
 * WebImageView.cpp
 *
 *  Created on: 4 oct. 2012
 *      Author: schutz
 */

#include "WebImageView.hpp"
#include <bb/cascades/Image>
//#include <QtGui/qimage.h>

QNetworkAccessManager * WebImageView::mNetManager = new QNetworkAccessManager;

WebImageView::WebImageView() {

}

const QUrl& WebImageView::url() const {
	return mUrl;
}

void WebImageView::setUrl(const QUrl& url) {

	mUrl = url;
	mLoading = 0;
	QNetworkReply * reply = mNetManager->get(QNetworkRequest(url));
	connect(reply, SIGNAL(finished()), this, SLOT(imageLoaded()));
	connect(reply, SIGNAL(downloadProgress ( qint64 , qint64 )), this,
			SLOT(dowloadProgressed(qint64,qint64)));
	emit urlChanged();
}

double WebImageView::loading() const {
	return mLoading;
}

void WebImageView::imageLoaded() {

	//QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());
	//setImage(Image(reply->readAll()));

	//reply->deleteLater();

	QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());

	QImage qimage;
	qimage.loadFromData(reply->readAll());

	qimage = qimage.scaledToWidth(800, Qt::FastTransformation);

	const QImage swappedImage = qimage.rgbSwapped();
	const bb::ImageData imageData = bb::ImageData::fromPixels(
			swappedImage.bits(), bb::PixelFormat::RGBX, swappedImage.width(),
			swappedImage.height(), swappedImage.bytesPerLine());

	bb::cascades::Image m_image = bb::cascades::Image(imageData);
	setImage(Image(m_image));

	reply->deleteLater();

}

void WebImageView::dowloadProgressed(qint64 bytes, qint64 total) {

	mLoading = double(bytes) / double(total);
	emit loadingChanged();

}

