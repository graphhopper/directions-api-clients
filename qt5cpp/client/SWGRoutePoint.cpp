/**
 * GraphHopper Directions API
 * You use the GraphHopper Directions API to add route planning, navigation and route optimization to your software. E.g. the Routing API has turn instructions and elevation data and the Route Optimization API solves your logistic problems and supports various constraints like time window and capacity restrictions. Also it is possible to get all distances between all locations with our fast Matrix API.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGRoutePoint.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGRoutePoint::SWGRoutePoint(QString* json) {
    init();
    this->fromJson(*json);
}

SWGRoutePoint::SWGRoutePoint() {
    init();
}

SWGRoutePoint::~SWGRoutePoint() {
    this->cleanup();
}

void
SWGRoutePoint::init() {
    type = new QString("");
    coordinates = new QList<SWGObject*>();
}

void
SWGRoutePoint::cleanup() {
    
    if(type != nullptr) {
        delete type;
    }

    if(coordinates != nullptr) {
        QList<SWGObject*>* arr = coordinates;
        foreach(SWGObject* o, *arr) {
            delete o;
        }
        delete coordinates;
    }
}

SWGRoutePoint*
SWGRoutePoint::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGRoutePoint::fromJsonObject(QJsonObject &pJson) {
    ::Swagger::setValue(&type, pJson["type"], "QString", "QString");
    
    ::Swagger::setValue(&coordinates, pJson["coordinates"], "QList", "SWGObject");
    
}

QString
SWGRoutePoint::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGRoutePoint::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    toJsonValue(QString("type"), type, obj, QString("QString"));

    QJsonArray coordinatesJsonArray;
    toJsonArray((QList<void*>*)coordinates, &coordinatesJsonArray, "coordinates", "SWGObject");
    obj->insert("coordinates", coordinatesJsonArray);

    return obj;
}

QString*
SWGRoutePoint::getType() {
    return type;
}
void
SWGRoutePoint::setType(QString* type) {
    this->type = type;
}

QList<SWGObject*>*
SWGRoutePoint::getCoordinates() {
    return coordinates;
}
void
SWGRoutePoint::setCoordinates(QList<SWGObject*>* coordinates) {
    this->coordinates = coordinates;
}



} /* namespace Swagger */

