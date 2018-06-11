part of swagger.api;

@Entity()
class Solution {
  /* overall costs of solution */
  @Property(name: 'costs')
  int costs = null;
  
/* overall travel distance in meters */
  @Property(name: 'distance')
  int distance = null;
  
/* overall transport time in seconds */
  @Property(name: 'time')
  int time = null;
  
/* overall transport time in seconds */
  @Property(name: 'transport_time')
  int transportTime = null;
  
/* operation time of the longest route in seconds */
  @Property(name: 'max_operation_time')
  int maxOperationTime = null;
  
/* total waiting time in seconds */
  @Property(name: 'waiting_time')
  int waitingTime = null;
  
/* number of employed vehicles */
  @Property(name: 'no_vehicles')
  int noVehicles = null;
  
/* number of jobs that could not be assigned to final solution */
  @Property(name: 'no_unassigned')
  int noUnassigned = null;
  
/* An array of routes */
  @Property(name: 'routes')
  List<Route> routes = [];
  

  @Property(name: 'unassigned')
  SolutionUnassigned unassigned = null;
  
  Solution();

  @override
  String toString()  {
    return 'Solution[costs=$costs, distance=$distance, time=$time, transportTime=$transportTime, maxOperationTime=$maxOperationTime, waitingTime=$waitingTime, noVehicles=$noVehicles, noUnassigned=$noUnassigned, routes=$routes, unassigned=$unassigned, ]';
  }
}

