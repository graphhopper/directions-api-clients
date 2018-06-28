part of openapi.api;

class VehicleType {
  /* Unique identifier for the vehicle type */
  String typeId = null;
  /* Profile of vehicle type */
  String profile = null;
  //enum profileEnum {  car,  bike,  foot,  hike,  mtb,  racingbike,  scooter,  truck,  small_truck,  };{
  /* array of capacity dimensions */
  List<int> capacity = [];
  /* speed_factor of vehicle type */
  double speedFactor = null;
  /* service time factor of vehicle type */
  double serviceTimeFactor = null;
  /* cost parameter per distance unit, here meter is used */
  double costPerMeter = null;
  /* cost parameter per time unit, here second is used */
  double costPerSecond = null;
  /* cost parameter vehicle activation, i.e. fixed costs per vehicle */
  double costPerActivation = null;
  VehicleType();

  @override
  String toString() {
    return 'VehicleType[typeId=$typeId, profile=$profile, capacity=$capacity, speedFactor=$speedFactor, serviceTimeFactor=$serviceTimeFactor, costPerMeter=$costPerMeter, costPerSecond=$costPerSecond, costPerActivation=$costPerActivation, ]';
  }

  VehicleType.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    typeId = json['typeId'];
    profile = json['profile'];
    capacity = (json['capacity'] as List).map((item) => item as int).toList();
    speedFactor = json['speedFactor'];
    serviceTimeFactor = json['serviceTimeFactor'];
    costPerMeter = json['costPerMeter'];
    costPerSecond = json['costPerSecond'];
    costPerActivation = json['costPerActivation'];
  }

  Map<String, dynamic> toJson() {
    return {
      'typeId': typeId,
      'profile': profile,
      'capacity': capacity,
      'speedFactor': speedFactor,
      'serviceTimeFactor': serviceTimeFactor,
      'costPerMeter': costPerMeter,
      'costPerSecond': costPerSecond,
      'costPerActivation': costPerActivation
    };
  }

  static List<VehicleType> listFromJson(List<dynamic> json) {
    return json == null ? new List<VehicleType>() : json.map((value) => new VehicleType.fromJson(value)).toList();
  }

  static Map<String, VehicleType> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, VehicleType>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new VehicleType.fromJson(value));
    }
    return map;
  }
}

