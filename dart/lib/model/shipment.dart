part of openapi.api;

class Shipment {
  /* Unique identifier of service */
  String id = null;
  /* name of shipment */
  String name = null;
  /* priority of service, i.e. 1 = high, 2 = normal, 3 = low. default is 2. */
  int priority = null;
  
  Stop pickup = null;
  
  Stop delivery = null;
  /* array of capacity dimensions */
  List<int> size = [];
  /* array of required skills */
  List<String> requiredSkills = [];
  /* array of allowed vehicle ids */
  List<String> allowedVehicles = [];
  /* array of disallowed vehicle ids */
  List<String> disallowedVehicles = [];
  /* max time shipment can stay in vehicle */
  int maxTimeInVehicle = null;
  Shipment();

  @override
  String toString() {
    return 'Shipment[id=$id, name=$name, priority=$priority, pickup=$pickup, delivery=$delivery, size=$size, requiredSkills=$requiredSkills, allowedVehicles=$allowedVehicles, disallowedVehicles=$disallowedVehicles, maxTimeInVehicle=$maxTimeInVehicle, ]';
  }

  Shipment.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    id = json['id'];
    name = json['name'];
    priority = json['priority'];
    pickup = new Stop.fromJson(json['pickup']);
    delivery = new Stop.fromJson(json['delivery']);
    size = (json['size'] as List).map((item) => item as int).toList();
    requiredSkills = (json['requiredSkills'] as List).map((item) => item as String).toList();
    allowedVehicles = (json['allowedVehicles'] as List).map((item) => item as String).toList();
    disallowedVehicles = (json['disallowedVehicles'] as List).map((item) => item as String).toList();
    maxTimeInVehicle = json['maxTimeInVehicle'];
  }

  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'name': name,
      'priority': priority,
      'pickup': pickup,
      'delivery': delivery,
      'size': size,
      'requiredSkills': requiredSkills,
      'allowedVehicles': allowedVehicles,
      'disallowedVehicles': disallowedVehicles,
      'maxTimeInVehicle': maxTimeInVehicle
    };
  }

  static List<Shipment> listFromJson(List<dynamic> json) {
    return json == null ? new List<Shipment>() : json.map((value) => new Shipment.fromJson(value)).toList();
  }

  static Map<String, Shipment> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Shipment>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Shipment.fromJson(value));
    }
    return map;
  }
}

