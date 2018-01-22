part of swagger.api;

@Entity()
class IsochroneResponsePolygon {
  
  @Property(name: 'properties')
  IsochroneResponsePolygonProperties properties = null;
  

  @Property(name: 'type')
  String type = null;
  

  @Property(name: 'geometry')
  IsochroneResponsePolygonGeometry geometry = null;
  
  IsochroneResponsePolygon();

  @override
  String toString()  {
    return 'IsochroneResponsePolygon[properties=$properties, type=$type, geometry=$geometry, ]';
  }
}

