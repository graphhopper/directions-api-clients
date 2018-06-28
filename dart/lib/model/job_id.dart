part of openapi.api;

class JobId {
  /* unique id for your job/request with which you can fetch your solution */
  String jobId = null;
  JobId();

  @override
  String toString() {
    return 'JobId[jobId=$jobId, ]';
  }

  JobId.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    jobId = json['jobId'];
  }

  Map<String, dynamic> toJson() {
    return {
      'jobId': jobId
    };
  }

  static List<JobId> listFromJson(List<dynamic> json) {
    return json == null ? new List<JobId>() : json.map((value) => new JobId.fromJson(value)).toList();
  }

  static Map<String, JobId> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, JobId>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new JobId.fromJson(value));
    }
    return map;
  }
}

