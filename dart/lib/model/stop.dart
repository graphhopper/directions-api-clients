part of openapi.api;

class Stop {
  
  Address address = null;
  /* duration of stop, i.e. time in seconds the corresponding activity takes */
  int duration = null;
  /* preparation time of service, e.g. search for a parking space. it only falls due if the location of previous activity differs from this location */
  int preparationTime = null;
  /* array of time windows. currently, only a single time window is allowed */
  List<TimeWindow> timeWindows = [];
  Stop();

  @override
  String toString() {
    return 'Stop[address=$address, duration=$duration, preparationTime=$preparationTime, timeWindows=$timeWindows, ]';
  }

  Stop.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    address = new Address.fromJson(json['address']);
    duration = json['duration'];
    preparationTime = json['preparationTime'];
    timeWindows = TimeWindow.listFromJson(json['timeWindows']);
  }

  Map<String, dynamic> toJson() {
    return {
      'address': address,
      'duration': duration,
      'preparationTime': preparationTime,
      'timeWindows': timeWindows
    };
  }

  static List<Stop> listFromJson(List<dynamic> json) {
    return json == null ? new List<Stop>() : json.map((value) => new Stop.fromJson(value)).toList();
  }

  static Map<String, Stop> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Stop>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Stop.fromJson(value));
    }
    return map;
  }
}

