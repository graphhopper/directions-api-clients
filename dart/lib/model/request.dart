part of openapi.api;

class Request {
  /* An array of vehicles that can be employed */
  List<Vehicle> vehicles = [];
  /* An array of vehicle types */
  List<VehicleType> vehicleTypes = [];
  /* An array of services */
  List<Service> services = [];
  /* An array of shipments */
  List<Shipment> shipments = [];
  /* An array of relations */
  List<Relation> relations = [];
  
  Algorithm algorithm = null;
  /* An array of objectives */
  List<Objective> objectives = [];
  /* An array of cost matrices */
  List<CostMatrix> costMatrices = [];
  
  Configuration configuration = null;
  Request();

  @override
  String toString() {
    return 'Request[vehicles=$vehicles, vehicleTypes=$vehicleTypes, services=$services, shipments=$shipments, relations=$relations, algorithm=$algorithm, objectives=$objectives, costMatrices=$costMatrices, configuration=$configuration, ]';
  }

  Request.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    vehicles = Vehicle.listFromJson(json['vehicles']);
    vehicleTypes = VehicleType.listFromJson(json['vehicleTypes']);
    services = Service.listFromJson(json['services']);
    shipments = Shipment.listFromJson(json['shipments']);
    relations = Relation.listFromJson(json['relations']);
    algorithm = new Algorithm.fromJson(json['algorithm']);
    objectives = Objective.listFromJson(json['objectives']);
    costMatrices = CostMatrix.listFromJson(json['costMatrices']);
    configuration = new Configuration.fromJson(json['configuration']);
  }

  Map<String, dynamic> toJson() {
    return {
      'vehicles': vehicles,
      'vehicleTypes': vehicleTypes,
      'services': services,
      'shipments': shipments,
      'relations': relations,
      'algorithm': algorithm,
      'objectives': objectives,
      'costMatrices': costMatrices,
      'configuration': configuration
    };
  }

  static List<Request> listFromJson(List<dynamic> json) {
    return json == null ? new List<Request>() : json.map((value) => new Request.fromJson(value)).toList();
  }

  static Map<String, Request> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Request>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Request.fromJson(value));
    }
    return map;
  }
}

