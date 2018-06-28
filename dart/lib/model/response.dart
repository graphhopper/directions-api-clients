part of openapi.api;

class Response {
  
  List<String> copyrights = [];
  /* unique identify of job - which you get when posting your request to the large problem solver */
  String jobId = null;
  /* indicates the current status of the job */
  String status = null;
  //enum statusEnum {  waiting_in_queue,  processing,  finished,  };{
  /* waiting time in ms */
  int waitingInQueue = null;
  /* processing time in ms. if job is still waiting in queue, processing_time is 0 */
  int processingTime = null;
  
  Solution solution = null;
  Response();

  @override
  String toString() {
    return 'Response[copyrights=$copyrights, jobId=$jobId, status=$status, waitingInQueue=$waitingInQueue, processingTime=$processingTime, solution=$solution, ]';
  }

  Response.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    copyrights = (json['copyrights'] as List).map((item) => item as String).toList();
    jobId = json['jobId'];
    status = json['status'];
    waitingInQueue = json['waitingInQueue'];
    processingTime = json['processingTime'];
    solution = new Solution.fromJson(json['solution']);
  }

  Map<String, dynamic> toJson() {
    return {
      'copyrights': copyrights,
      'jobId': jobId,
      'status': status,
      'waitingInQueue': waitingInQueue,
      'processingTime': processingTime,
      'solution': solution
    };
  }

  static List<Response> listFromJson(List<dynamic> json) {
    return json == null ? new List<Response>() : json.map((value) => new Response.fromJson(value)).toList();
  }

  static Map<String, Response> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Response>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Response.fromJson(value));
    }
    return map;
  }
}

