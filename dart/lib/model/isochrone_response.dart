part of swagger.api;

@Entity()
class IsochroneResponse {
  
  @Property(name: 'polygons')
  List<IsochroneResponsePolygon> polygons = [];
  

  @Property(name: 'copyrights')
  List<String> copyrights = [];
  
  IsochroneResponse();

  @override
  String toString()  {
    return 'IsochroneResponse[polygons=$polygons, copyrights=$copyrights, ]';
  }
}

