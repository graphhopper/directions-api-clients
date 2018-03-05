part of swagger.api;

@Entity()
class Activity {
  /* type of activity */
  @Property(name: 'type')
  String type = null;
  //enum typeEnum {  start,  end,  service,  pickupShipment,  deliverShipment,  pickup,  delivery,  break,  };
/* id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to */
  @Property(name: 'id')
  String id = null;
  
/* id that refers to address */
  @Property(name: 'location_id')
  String locationId = null;
  
/* arrival time at this activity in seconds */
  @Property(name: 'arr_time')
  int arrTime = null;
  
/* end time of and thus departure time at this activity */
  @Property(name: 'end_time')
  int endTime = null;
  
/* waiting time at this activity in seconds */
  @Property(name: 'waiting_time')
  int waitingTime = null;
  
/* cumulated distance from start to this activity in m */
  @Property(name: 'distance')
  int distance = null;
  
/* driving time of driver in seconds */
  @Property(name: 'driving_time')
  int drivingTime = null;
  
/* Array with size/capacity dimensions before this activity */
  @Property(name: 'load_before')
  List<int> loadBefore = [];
  
/* Array with size/capacity dimensions after this activity */
  @Property(name: 'load_after')
  List<int> loadAfter = [];
  
  Activity();

  @override
  String toString()  {
    return 'Activity[type=$type, id=$id, locationId=$locationId, arrTime=$arrTime, endTime=$endTime, waitingTime=$waitingTime, distance=$distance, drivingTime=$drivingTime, loadBefore=$loadBefore, loadAfter=$loadAfter, ]';
  }
}

