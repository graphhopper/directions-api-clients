part of openapi.api;

class Vehicle {
  /* Unique identifier of vehicle */
  String vehicleId = null;
  /* Unique identifier referring to the available vehicle types */
  String typeId = null;
  
  Address startAddress = null;
  
  Address endAddress = null;
  
  ModelBreak break_ = null;
  /* Indicates whether vehicle should return to start address or not. If not, it can end at any service activity. */
  bool returnToDepot = null;
  /* earliest start of vehicle at its start location */
  int earliestStart = null;
  /* latest end of vehicle at its end location */
  int latestEnd = null;
  /* array of skills */
  List<String> skills = [];
  /* max distance of vehicle */
  int maxDistance = null;
  /* max drive time of vehicle */
  int maxDrivingTime = null;
  /* max number of jobs the vehicle can load */
  int maxJobs = null;
  /* max number of activities the vehicle can conduct */
  int maxActivities = null;
  Vehicle();

  @override
  String toString() {
    return 'Vehicle[vehicleId=$vehicleId, typeId=$typeId, startAddress=$startAddress, endAddress=$endAddress, break_=$break_, returnToDepot=$returnToDepot, earliestStart=$earliestStart, latestEnd=$latestEnd, skills=$skills, maxDistance=$maxDistance, maxDrivingTime=$maxDrivingTime, maxJobs=$maxJobs, maxActivities=$maxActivities, ]';
  }

  Vehicle.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    vehicleId = json['vehicleId'];
    typeId = json['typeId'];
    startAddress = new Address.fromJson(json['startAddress']);
    endAddress = new Address.fromJson(json['endAddress']);
    break_ = new ModelBreak.fromJson(json['break_']);
    returnToDepot = json['returnToDepot'];
    earliestStart = json['earliestStart'];
    latestEnd = json['latestEnd'];
    skills = (json['skills'] as List).map((item) => item as String).toList();
    maxDistance = json['maxDistance'];
    maxDrivingTime = json['maxDrivingTime'];
    maxJobs = json['maxJobs'];
    maxActivities = json['maxActivities'];
  }

  Map<String, dynamic> toJson() {
    return {
      'vehicleId': vehicleId,
      'typeId': typeId,
      'startAddress': startAddress,
      'endAddress': endAddress,
      'break_': break_,
      'returnToDepot': returnToDepot,
      'earliestStart': earliestStart,
      'latestEnd': latestEnd,
      'skills': skills,
      'maxDistance': maxDistance,
      'maxDrivingTime': maxDrivingTime,
      'maxJobs': maxJobs,
      'maxActivities': maxActivities
    };
  }

  static List<Vehicle> listFromJson(List<dynamic> json) {
    return json == null ? new List<Vehicle>() : json.map((value) => new Vehicle.fromJson(value)).toList();
  }

  static Map<String, Vehicle> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Vehicle>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Vehicle.fromJson(value));
    }
    return map;
  }
}

