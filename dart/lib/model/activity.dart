part of openapi.api;

class Activity {
  /* type of activity */
  String type = null;
  //enum typeEnum {  start,  end,  service,  pickupShipment,  deliverShipment,  pickup,  delivery,  break,  };{
  /* id referring to the underlying service or shipment, i.e. the shipment or service this activity belongs to */
  String id = null;
  /* id that refers to address */
  String locationId = null;
  /* arrival time at this activity in seconds */
  int arrTime = null;
  /* end time of and thus departure time at this activity */
  int endTime = null;
  /* waiting time at this activity in seconds */
  int waitingTime = null;
  /* cumulated distance from start to this activity in m */
  int distance = null;
  /* driving time of driver in seconds */
  int drivingTime = null;
  /* Array with size/capacity dimensions before this activity */
  List<int> loadBefore = [];
  /* Array with size/capacity dimensions after this activity */
  List<int> loadAfter = [];
  Activity();

  @override
  String toString() {
    return 'Activity[type=$type, id=$id, locationId=$locationId, arrTime=$arrTime, endTime=$endTime, waitingTime=$waitingTime, distance=$distance, drivingTime=$drivingTime, loadBefore=$loadBefore, loadAfter=$loadAfter, ]';
  }

  Activity.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    type = json['type'];
    id = json['id'];
    locationId = json['locationId'];
    arrTime = json['arrTime'];
    endTime = json['endTime'];
    waitingTime = json['waitingTime'];
    distance = json['distance'];
    drivingTime = json['drivingTime'];
    loadBefore = (json['loadBefore'] as List).map((item) => item as int).toList();
    loadAfter = (json['loadAfter'] as List).map((item) => item as int).toList();
  }

  Map<String, dynamic> toJson() {
    return {
      'type': type,
      'id': id,
      'locationId': locationId,
      'arrTime': arrTime,
      'endTime': endTime,
      'waitingTime': waitingTime,
      'distance': distance,
      'drivingTime': drivingTime,
      'loadBefore': loadBefore,
      'loadAfter': loadAfter
    };
  }

  static List<Activity> listFromJson(List<dynamic> json) {
    return json == null ? new List<Activity>() : json.map((value) => new Activity.fromJson(value)).toList();
  }

  static Map<String, Activity> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Activity>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Activity.fromJson(value));
    }
    return map;
  }
}

