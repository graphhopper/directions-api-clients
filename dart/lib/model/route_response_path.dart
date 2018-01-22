part of swagger.api;

@Entity()
class RouteResponsePath {
  /* The total distance of the route, in meter */
  @Property(name: 'distance')
  double distance = null;
  
/* The total time of the route, in ms */
  @Property(name: 'time')
  int time = null;
  

  @Property(name: 'ascend')
  double ascend = null;
  
/* The total descend (downhill) of the route, in meter */
  @Property(name: 'descend')
  double descend = null;
  

  @Property(name: 'points')
  ResponseCoordinates points = null;
  
/* Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version */
  @Property(name: 'points_encoded')
  bool pointsEncoded = null;
  
/* The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat */
  @Property(name: 'bbox')
  List<double> bbox = [];
  

  @Property(name: 'snapped_waypoints')
  ResponseCoordinates snappedWaypoints = null;
  

  @Property(name: 'instructions')
  ResponseInstructions instructions = null;
  
  RouteResponsePath();

  @override
  String toString()  {
    return 'RouteResponsePath[distance=$distance, time=$time, ascend=$ascend, descend=$descend, points=$points, pointsEncoded=$pointsEncoded, bbox=$bbox, snappedWaypoints=$snappedWaypoints, instructions=$instructions, ]';
  }
}

