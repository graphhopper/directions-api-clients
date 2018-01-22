part of swagger.api;

@Entity()
class Route {
  /* id of vehicle that operates route */
  @Property(name: 'vehicle_id')
  String vehicleId = null;
  
/* distance of route in meter */
  @Property(name: 'distance')
  int distance = null;
  
/* transport time of route in ms */
  @Property(name: 'transport_time')
  int transportTime = null;
  
/* completion time of route in ms */
  @Property(name: 'completion_time')
  int completionTime = null;
  
/* waiting time of route in ms */
  @Property(name: 'waiting_time')
  int waitingTime = null;
  
/* array of activities */
  @Property(name: 'activities')
  List<Activity> activities = [];
  
/* array of route planning points */
  @Property(name: 'points')
  List<RoutePoint> points = [];
  
  Route();

  @override
  String toString()  {
    return 'Route[vehicleId=$vehicleId, distance=$distance, transportTime=$transportTime, completionTime=$completionTime, waitingTime=$waitingTime, activities=$activities, points=$points, ]';
  }
}

