part of openapi.api;

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
          return new Activity.fromJson(value);
        case 'Address':
          return new Address.fromJson(value);
        case 'Algorithm':
          return new Algorithm.fromJson(value);
        case 'Configuration':
          return new Configuration.fromJson(value);
        case 'CostMatrix':
          return new CostMatrix.fromJson(value);
        case 'Detail':
          return new Detail.fromJson(value);
        case 'GHError':
          return new GHError.fromJson(value);
        case 'GeocodingLocation':
          return new GeocodingLocation.fromJson(value);
        case 'GeocodingPoint':
          return new GeocodingPoint.fromJson(value);
        case 'GeocodingResponse':
          return new GeocodingResponse.fromJson(value);
        case 'IsochroneResponse':
          return new IsochroneResponse.fromJson(value);
        case 'IsochroneResponsePolygon':
          return new IsochroneResponsePolygon.fromJson(value);
        case 'JobId':
          return new JobId.fromJson(value);
        case 'Location':
          return new Location.fromJson(value);
        case 'MatrixRequest':
          return new MatrixRequest.fromJson(value);
        case 'MatrixResponse':
          return new MatrixResponse.fromJson(value);
        case 'ModelBreak':
          return new ModelBreak.fromJson(value);
        case 'Objective':
          return new Objective.fromJson(value);
        case 'Relation':
          return new Relation.fromJson(value);
        case 'Request':
          return new Request.fromJson(value);
        case 'Response':
          return new Response.fromJson(value);
        case 'ResponseCoordinates':
          return new ResponseCoordinates.fromJson(value);
        case 'ResponseCoordinatesArray':
          return new ResponseCoordinatesArray.fromJson(value);
        case 'ResponseInfo':
          return new ResponseInfo.fromJson(value);
        case 'ResponseInstruction':
          return new ResponseInstruction.fromJson(value);
        case 'ResponseInstructions':
          return new ResponseInstructions.fromJson(value);
        case 'Route':
          return new Route.fromJson(value);
        case 'RoutePoint':
          return new RoutePoint.fromJson(value);
        case 'RouteResponse':
          return new RouteResponse.fromJson(value);
        case 'RouteResponsePath':
          return new RouteResponsePath.fromJson(value);
        case 'Routing':
          return new Routing.fromJson(value);
        case 'Service':
          return new Service.fromJson(value);
        case 'Shipment':
          return new Shipment.fromJson(value);
        case 'Solution':
          return new Solution.fromJson(value);
        case 'Stop':
          return new Stop.fromJson(value);
        case 'TimeWindow':
          return new TimeWindow.fromJson(value);
        case 'Vehicle':
          return new Vehicle.fromJson(value);
        case 'VehicleType':
          return new VehicleType.fromJson(value);
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
    } else {
      serialized = JSON.encode(obj);
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

  void setAccessToken(String accessToken) {
    _authentications.forEach((key, auth) {
      if (auth is OAuth) {
        auth.setAccessToken(accessToken);
      }
    });
  }
}
