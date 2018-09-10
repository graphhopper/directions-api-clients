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
  
/* address of activity */
  @Property(name: 'address')
  Address address = null;
  
/* arrival time at this activity in seconds */
  @Property(name: 'arr_time')
  int arrTime = null;
  
/* end time of and thus departure time at this activity */
  @Property(name: 'end_time')
  int endTime = null;
  
/* end date time with offset like this 1970-01-01T01:00+01:00 */
  @Property(name: 'end_date_time')
  String endDateTime = null;
  
/* arrival date time with offset like this 1970-01-01T01:00+01:00 */
  @Property(name: 'arr_date_time')
  String arrDateTime = null;
  
/* waiting time at this activity in seconds */
  @Property(name: 'waiting_time')
  int waitingTime = null;
  
/* preparation time at this activity in seconds */
  @Property(name: 'preparation_time')
  int preparationTime = null;
  
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
    return 'Activity[type=$type, id=$id, locationId=$locationId, address=$address, arrTime=$arrTime, endTime=$endTime, endDateTime=$endDateTime, arrDateTime=$arrDateTime, waitingTime=$waitingTime, preparationTime=$preparationTime, distance=$distance, drivingTime=$drivingTime, loadBefore=$loadBefore, loadAfter=$loadAfter, ]';
  }
}

