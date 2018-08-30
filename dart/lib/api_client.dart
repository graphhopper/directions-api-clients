part of swagger.api;

class QueryParam {
  String name;
  String value;

  QueryParam(this.name, this.value);
}

class ApiClient {

  String basePath;
  var client = new BrowserClient();

  Map<String, String> _defaultHeaderMap = {};
  Map<String, Authentication> _authentications = {};

  final dson = new Dartson.JSON()
      ..addTransformer(new DateTimeParser(), DateTime);

  final _RegList = new RegExp(r'^List<(.*)>$');
  final _RegMap = new RegExp(r'^Map<String,(.*)>$');

  ApiClient({this.basePath: "https://graphhopper.com/api/1"}) {
    // Setup authentications (key: authentication name, value: authentication).
    _authentications['api_key'] = new ApiKeyAuth("query", "key");
  }

  void addDefaultHeader(String key, String value) {
     _defaultHeaderMap[key] = value;
  }

  dynamic _deserialize(dynamic value, String targetType) {
    try {
      switch (targetType) {
        case 'String':
          return '$value';
        case 'int':
          return value is int ? value : int.parse('$value');
        case 'bool':
          return value is bool ? value : '$value'.toLowerCase() == 'true';
        case 'double':
          return value is double ? value : double.parse('$value');
        case 'Activity':
          return dson.map(value, new Activity());
        case 'Address':
          return dson.map(value, new Address());
        case 'Configuration':
          return dson.map(value, new Configuration());
        case 'CostMatrix':
          return dson.map(value, new CostMatrix());
        case 'CostMatrixData':
          return dson.map(value, new CostMatrixData());
        case 'CostMatrixDataInfo':
          return dson.map(value, new CostMatrixDataInfo());
        case 'Detail':
          return dson.map(value, new Detail());
        case 'GHError':
          return dson.map(value, new GHError());
        case 'GHErrorHints':
          return dson.map(value, new GHErrorHints());
        case 'GeocodingLocation':
          return dson.map(value, new GeocodingLocation());
        case 'GeocodingPoint':
          return dson.map(value, new GeocodingPoint());
        case 'GeocodingResponse':
          return dson.map(value, new GeocodingResponse());
        case 'IsochroneResponse':
          return dson.map(value, new IsochroneResponse());
        case 'IsochroneResponsePolygon':
          return dson.map(value, new IsochroneResponsePolygon());
        case 'IsochroneResponsePolygonGeometry':
          return dson.map(value, new IsochroneResponsePolygonGeometry());
        case 'IsochroneResponsePolygonProperties':
          return dson.map(value, new IsochroneResponsePolygonProperties());
        case 'JobId':
          return dson.map(value, new JobId());
        case 'Location':
          return dson.map(value, new Location());
        case 'MatrixRequest':
          return dson.map(value, new MatrixRequest());
        case 'MatrixResponse':
          return dson.map(value, new MatrixResponse());
        case 'ModelBreak':
          return dson.map(value, new ModelBreak());
        case 'Objective':
          return dson.map(value, new Objective());
        case 'Relation':
          return dson.map(value, new Relation());
        case 'Request':
          return dson.map(value, new Request());
        case 'Response':
          return dson.map(value, new Response());
        case 'ResponseCoordinates':
          return dson.map(value, new ResponseCoordinates());
        case 'ResponseCoordinatesArray':
          return dson.map(value, new ResponseCoordinatesArray());
        case 'ResponseInfo':
          return dson.map(value, new ResponseInfo());
        case 'ResponseInstruction':
          return dson.map(value, new ResponseInstruction());
        case 'ResponseInstructions':
          return dson.map(value, new ResponseInstructions());
        case 'Route':
          return dson.map(value, new Route());
        case 'RoutePoint':
          return dson.map(value, new RoutePoint());
        case 'RouteResponse':
          return dson.map(value, new RouteResponse());
        case 'RouteResponsePath':
          return dson.map(value, new RouteResponsePath());
        case 'Routing':
          return dson.map(value, new Routing());
        case 'Service':
          return dson.map(value, new Service());
        case 'Shipment':
          return dson.map(value, new Shipment());
        case 'Solution':
          return dson.map(value, new Solution());
        case 'SolutionUnassigned':
          return dson.map(value, new SolutionUnassigned());
        case 'Stop':
          return dson.map(value, new Stop());
        case 'TimeWindow':
          return dson.map(value, new TimeWindow());
        case 'Vehicle':
          return dson.map(value, new Vehicle());
        case 'VehicleType':
          return dson.map(value, new VehicleType());
        default:
          {
            Match match;
            if (value is List &&
                (match = _RegList.firstMatch(targetType)) != null) {
              var newTargetType = match[1];
              return value.map((v) => _deserialize(v, newTargetType)).toList();
            } else if (value is Map &&
                (match = _RegMap.firstMatch(targetType)) != null) {
              var newTargetType = match[1];
              return new Map.fromIterables(value.keys,
                  value.values.map((v) => _deserialize(v, newTargetType)));
            }
          }
      }
    } catch (e, stack) {
      throw new ApiException.withInner(500, 'Exception during deserialization.', e, stack);
    }
    throw new ApiException(500, 'Could not find a suitable class for deserialization');
  }

  dynamic deserialize(String json, String targetType) {
    // Remove all spaces.  Necessary for reg expressions as well.
    targetType = targetType.replaceAll(' ', '');

    if (targetType == 'String') return json;

    var decodedJson = JSON.decode(json);
    return _deserialize(decodedJson, targetType);
  }

  String serialize(Object obj) {
    String serialized = '';
    if (obj == null) {
      serialized = '';
    } else if (obj is String) {
      serialized = obj;
    } else {
      serialized = dson.encode(obj);
    }
    return serialized;
  }

  // We don't use a Map<String, String> for queryParams.
  // If collectionFormat is 'multi' a key might appear multiple times.
  Future<Response> invokeAPI(String path,
                             String method,
                             Iterable<QueryParam> queryParams,
                             Object body,
                             Map<String, String> headerParams,
                             Map<String, String> formParams,
                             String contentType,
                             List<String> authNames) async {

    _updateParamsForAuth(authNames, queryParams, headerParams);

    var ps = queryParams.where((p) => p.value != null).map((p) => '${p.name}=${p.value}');
    String queryString = ps.isNotEmpty ?
                         '?' + ps.join('&') :
                         '';

    String url = basePath + path + queryString;

    headerParams.addAll(_defaultHeaderMap);
    headerParams['Content-Type'] = contentType;

    if(body is MultipartRequest) {
      var request = new MultipartRequest(method, Uri.parse(url));
      request.fields.addAll(body.fields);
      request.files.addAll(body.files);
      request.headers.addAll(body.headers);
      request.headers.addAll(headerParams);
      var response = await client.send(request);
      return Response.fromStream(response);
    } else {
      var msgBody = contentType == "application/x-www-form-urlencoded" ? formParams : serialize(body);
      switch(method) {
        case "POST":
          return client.post(url, headers: headerParams, body: msgBody);
        case "PUT":
          return client.put(url, headers: headerParams, body: msgBody);
        case "DELETE":
          return client.delete(url, headers: headerParams);
        case "PATCH":
          return client.patch(url, headers: headerParams, body: msgBody);
        default:
          return client.get(url, headers: headerParams);
      }
    }
  }

  /// Update query and header parameters based on authentication settings.
  /// @param authNames The authentications to apply
  void _updateParamsForAuth(List<String> authNames, List<QueryParam> queryParams, Map<String, String> headerParams) {
    authNames.forEach((authName) {
      Authentication auth = _authentications[authName];
      if (auth == null) throw new ArgumentError("Authentication undefined: " + authName);
      auth.applyToParams(queryParams, headerParams);
    });
  }
}
