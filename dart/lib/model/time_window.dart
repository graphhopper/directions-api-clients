part of openapi.api;

class TimeWindow {
  /* earliest start time of corresponding activity */
  int earliest = null;
  /* latest start time of corresponding activity */
  int latest = null;
  TimeWindow();

  @override
  String toString() {
    return 'TimeWindow[earliest=$earliest, latest=$latest, ]';
  }

  TimeWindow.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    earliest = json['earliest'];
    latest = json['latest'];
  }

  Map<String, dynamic> toJson() {
    return {
      'earliest': earliest,
      'latest': latest
    };
  }

  static List<TimeWindow> listFromJson(List<dynamic> json) {
    return json == null ? new List<TimeWindow>() : json.map((value) => new TimeWindow.fromJson(value)).toList();
  }

  static Map<String, TimeWindow> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, TimeWindow>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new TimeWindow.fromJson(value));
    }
    return map;
  }
}

