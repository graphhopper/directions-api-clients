part of swagger.api;

@Entity()
class RoutePoint {
  
  @Property(name: 'type')
  String type = null;
  

  @Property(name: 'coordinates')
  List<Object> coordinates = [];
  
  RoutePoint();

  @override
  String toString()  {
    return 'RoutePoint[type=$type, coordinates=$coordinates, ]';
  }
}

