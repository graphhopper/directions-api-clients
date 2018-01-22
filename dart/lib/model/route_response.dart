part of swagger.api;

@Entity()
class RouteResponse {
  
  @Property(name: 'paths')
  List<RouteResponsePath> paths = [];
  

  @Property(name: 'info')
  ResponseInfo info = null;
  
  RouteResponse();

  @override
  String toString()  {
    return 'RouteResponse[paths=$paths, info=$info, ]';
  }
}

