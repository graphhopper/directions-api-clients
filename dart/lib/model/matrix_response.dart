part of openapi.api;

class MatrixResponse {
  
  List<List<double>> distances = [];
  
  List<List<double>> times = [];
  
  List<List<double>> weights = [];
  
  ResponseInfo info = null;
  MatrixResponse();

  @override
  String toString() {
    return 'MatrixResponse[distances=$distances, times=$times, weights=$weights, info=$info, ]';
  }

  MatrixResponse.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    distances = List.listFromJson(json['distances']);
    times = List.listFromJson(json['times']);
    weights = List.listFromJson(json['weights']);
    info = new ResponseInfo.fromJson(json['info']);
  }

  Map<String, dynamic> toJson() {
    return {
      'distances': distances,
      'times': times,
      'weights': weights,
      'info': info
    };
  }

  static List<MatrixResponse> listFromJson(List<dynamic> json) {
    return json == null ? new List<MatrixResponse>() : json.map((value) => new MatrixResponse.fromJson(value)).toList();
  }

  static Map<String, MatrixResponse> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, MatrixResponse>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new MatrixResponse.fromJson(value));
    }
    return map;
  }
}

