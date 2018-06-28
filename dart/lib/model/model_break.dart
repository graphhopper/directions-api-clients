part of openapi.api;

class ModelBreak {
  /* earliest start of break */
  int earliest = null;
  /* latest start of break */
  int latest = null;
  /* duration of break */
  int duration = null;
  /* max driving time without break */
  int maxDrivingTime = null;
  /* initial driving time, i.e. the time your driver has already spent for driving */
  int initialDrivingTime = null;
  /* array of splits */
  List<int> possibleSplit = [];
  ModelBreak();

  @override
  String toString() {
    return 'ModelBreak[earliest=$earliest, latest=$latest, duration=$duration, maxDrivingTime=$maxDrivingTime, initialDrivingTime=$initialDrivingTime, possibleSplit=$possibleSplit, ]';
  }

  ModelBreak.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    earliest = json['earliest'];
    latest = json['latest'];
    duration = json['duration'];
    maxDrivingTime = json['maxDrivingTime'];
    initialDrivingTime = json['initialDrivingTime'];
    possibleSplit = (json['possibleSplit'] as List).map((item) => item as int).toList();
  }

  Map<String, dynamic> toJson() {
    return {
      'earliest': earliest,
      'latest': latest,
      'duration': duration,
      'maxDrivingTime': maxDrivingTime,
      'initialDrivingTime': initialDrivingTime,
      'possibleSplit': possibleSplit
    };
  }

  static List<ModelBreak> listFromJson(List<dynamic> json) {
    return json == null ? new List<ModelBreak>() : json.map((value) => new ModelBreak.fromJson(value)).toList();
  }

  static Map<String, ModelBreak> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ModelBreak>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ModelBreak.fromJson(value));
    }
    return map;
  }
}

