part of swagger.api;

@Entity()
class IsochroneResponsePolygonGeometry {
  
  @Property(name: 'type')
  String type = null;
  

  @Property(name: 'coordinates')
  List<ResponseCoordinatesArray> coordinates = [];
  
  IsochroneResponsePolygonGeometry();

  @override
  String toString()  {
    return 'IsochroneResponsePolygonGeometry[type=$type, coordinates=$coordinates, ]';
  }
}

