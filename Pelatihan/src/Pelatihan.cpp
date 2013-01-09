// Default empty project template
#include "Pelatihan.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListView>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/GroupDataModel>
#include <WebImageView.hpp>

using namespace bb::cascades;

Pelatihan::Pelatihan(bb::cascades::Application *app) :
		QObject(app) {
	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime


	qmlRegisterType<WebImageView>("WebImageView", 1, 0, "WebImageView");
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);


	// create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	ListView *lv= root->findChild<ListView*>("listdata");

	bb::data::JsonDataAccess jda;

	QVariant data = jda.load(
			QDir::currentPath() + "/app/native/assets/db.json");

	QVariantList dataList = data.toList();

	qDebug()<< dataList.size();
	GroupDataModel *dm = new GroupDataModel(QStringList() << "id");
	dm->setGrouping(ItemGrouping::None);

	for (QList<QVariant>::iterator it = dataList.begin(); it != dataList.end();
			it++) {
		QVariantMap post = it->toMap();
		dm->insert(post);
	}


	lv->setDataModel(dm);


	// set created root object as a scene
	app->setScene(root);
}

