part of openapi.api;

class ResponseInstruction {
  /* A description what the user has to do in order to follow the route. The language depends on the locale parameter. */
  String text = null;
  /* The name of the street to turn onto in order to follow the route. */
  String streetName = null;
  /* The distance for this instruction, in meter */
  double distance = null;
  /* The duration for this instruction, in ms */
  int time = null;
  /* An array containing the first and the last index (relative to paths[0].points) of the points for this instruction. This is useful to know for which part of the route the instructions are valid. */
  List<int> interval = [];
  /* A number which specifies the sign to show e.g. for right turn etc <br>TURN_SHARP_LEFT = -3<br>TURN_LEFT = -2<br>TURN_SLIGHT_LEFT = -1<br>CONTINUE_ON_STREET = 0<br>TURN_SLIGHT_RIGHT = 1<br>TURN_RIGHT = 2<br>TURN_SHARP_RIGHT = 3<br>FINISH = 4<br>VIA_REACHED = 5<br>USE_ROUNDABOUT = 6 */
  int sign = null;
  /* optional - A text describing the instruction in more detail, e.g. like surface of the way, warnings or involved costs. */
  String annotationText = null;
  /* optional - 0 stands for INFO, 1 for warning, 2 for costs, 3 for costs and warning */
  int annotationImportance = null;
  /* optional - Only available for USE_ROUNDABOUT instructions. The count of exits at which the route leaves the roundabout. */
  int exitNumber = null;
  /* optional - Only available for USE_ROUNDABOUT instructions. The radian of the route within the roundabout - 0&lt;r&lt;2*PI for clockwise and -2PI&lt;r&lt;0 for counterclockwise transit. Null if the direction of rotation is undefined. */
  double turnAngle = null;
  ResponseInstruction();

  @override
  String toString() {
    return 'ResponseInstruction[text=$text, streetName=$streetName, distance=$distance, time=$time, interval=$interval, sign=$sign, annotationText=$annotationText, annotationImportance=$annotationImportance, exitNumber=$exitNumber, turnAngle=$turnAngle, ]';
  }

  ResponseInstruction.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    text = json['text'];
    streetName = json['streetName'];
    distance = json['distance'];
    time = json['time'];
    interval = (json['interval'] as List).map((item) => item as int).toList();
    sign = json['sign'];
    annotationText = json['annotationText'];
    annotationImportance = json['annotationImportance'];
    exitNumber = json['exitNumber'];
    turnAngle = json['turnAngle'];
  }

  Map<String, dynamic> toJson() {
    return {
      'text': text,
      'streetName': streetName,
      'distance': distance,
      'time': time,
      'interval': interval,
      'sign': sign,
      'annotationText': annotationText,
      'annotationImportance': annotationImportance,
      'exitNumber': exitNumber,
      'turnAngle': turnAngle
    };
  }

  static List<ResponseInstruction> listFromJson(List<dynamic> json) {
    return json == null ? new List<ResponseInstruction>() : json.map((value) => new ResponseInstruction.fromJson(value)).toList();
  }

  static Map<String, ResponseInstruction> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ResponseInstruction>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ResponseInstruction.fromJson(value));
    }
    return map;
  }
}

