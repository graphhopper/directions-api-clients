#import "SWGRoutingApi.h"
#import "SWGQueryParamCollection.h"
#import "SWGApiClient.h"
#import "SWGGHError.h"
#import "SWGRouteResponse.h"


@interface SWGRoutingApi ()

@property (nonatomic, strong, readwrite) NSMutableDictionary *mutableDefaultHeaders;

@end

@implementation SWGRoutingApi

NSString* kSWGRoutingApiErrorDomain = @"SWGRoutingApiErrorDomain";
NSInteger kSWGRoutingApiMissingParamErrorCode = 234513;

@synthesize apiClient = _apiClient;

#pragma mark - Initialize methods

- (instancetype) init {
    return [self initWithApiClient:[SWGApiClient sharedClient]];
}


-(instancetype) initWithApiClient:(SWGApiClient *)apiClient {
    self = [super init];
    if (self) {
        _apiClient = apiClient;
        _mutableDefaultHeaders = [NSMutableDictionary dictionary];
    }
    return self;
}

#pragma mark -

-(NSString*) defaultHeaderForKey:(NSString*)key {
    return self.mutableDefaultHeaders[key];
}

-(void) setDefaultHeaderValue:(NSString*) value forKey:(NSString*)key {
    [self.mutableDefaultHeaders setValue:value forKey:key];
}

-(NSDictionary *)defaultHeaders {
    return self.mutableDefaultHeaders;
}

#pragma mark - Api Methods

///
/// Routing Request
/// The GraphHopper Routing API allows to calculate route and implement navigation via the turn instructions
///  @param point Specify multiple points for which the route should be calculated. The order is important. Specify at least two points. 
///
///  @param pointsEncoded IMPORTANT- TODO - currently you have to pass false for the swagger client - Have not found a way to force add a parameter. If `false` the coordinates in `point` and `snapped_waypoints` are returned as array using the order [lon,lat,elevation] for every point. If `true` the coordinates will be encoded as string leading to less bandwith usage. You'll need a special handling for the decoding of this string on the client-side. We provide open source code in [Java](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/java/com/graphhopper/http/WebHelper.java#L43) and [JavaScript](https://github.com/graphhopper/graphhopper/blob/d70b63660ac5200b03c38ba3406b8f93976628a6/web/src/main/webapp/js/ghrequest.js#L139). It is especially important to use no 3rd party client if you set `elevation=true`! 
///
///  @param key Get your key at graphhopper.com 
///
///  @param locale The locale of the resulting turn instructions. E.g. `pt_PT` for Portuguese or `de` for German (optional)
///
///  @param instructions If instruction should be calculated and returned (optional)
///
///  @param vehicle The vehicle for which the route should be calculated. Other vehicles are foot, small_truck, ... (optional)
///
///  @param elevation If `true` a third dimension - the elevation - is included in the polyline or in the GeoJson. If enabled you have to use a modified version of the decoding method or set points_encoded to `false`. See the points_encoded attribute for more details. Additionally a request can fail if the vehicle does not support elevation. See the features object for every vehicle. (optional)
///
///  @param calcPoints If the points for the route should be calculated at all printing out only distance and time. (optional)
///
///  @param pointHint Optional parameter. Specifies a hint for each `point` parameter to prefer a certain street for the closest location lookup. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. (optional)
///
///  @param chDisable Use this parameter in combination with one or more parameters of this table (optional)
///
///  @param weighting Which kind of 'best' route calculation you need. Other option is `shortest` (e.g. for `vehicle=foot` or `bike`), `short_fastest` if time and distance is expensive e.g. for `vehicle=truck` (optional)
///
///  @param edgeTraversal Use `true` if you want to consider turn restrictions for bike and motor vehicles. Keep in mind that the response time is roughly 2 times slower. (optional)
///
///  @param algorithm The algorithm to calculate the route. Other options are `dijkstra`, `astar`, `astarbi`, `alternative_route` and `round_trip` (optional)
///
///  @param heading Favour a heading direction for a certain point. Specify either one heading for the start point or as many as there are points. In this case headings are associated by their order to the specific points. Headings are given as north based clockwise angle between 0 and 360 degree. This parameter also influences the tour generated with `algorithm=round_trip` and force the initial direction. (optional)
///
///  @param headingPenalty Penalty for omitting a specified heading. The penalty corresponds to the accepted time delay in seconds in comparison to the route without a heading. (optional)
///
///  @param passThrough If `true` u-turns are avoided at via-points with regard to the `heading_penalty`. (optional)
///
///  @param roundTripDistance If `algorithm=round_trip` this parameter configures approximative length of the resulting round trip (optional)
///
///  @param roundTripSeed If `algorithm=round_trip` this parameter introduces randomness if e.g. the first try wasn't good. (optional)
///
///  @param alternativeRouteMaxPaths If `algorithm=alternative_route` this parameter sets the number of maximum paths which should be calculated. Increasing can lead to worse alternatives. (optional)
///
///  @param alternativeRouteMaxWeightFactor If `algorithm=alternative_route` this parameter sets the factor by which the alternatives routes can be longer than the optimal route. Increasing can lead to worse alternatives. (optional)
///
///  @param alternativeRouteMaxShareFactor If `algorithm=alternative_route` this parameter specifies how much alternatives routes can have maximum in common with the optimal route. Increasing can lead to worse alternatives. (optional)
///
///  @returns SWGRouteResponse*
///
-(NSURLSessionTask*) routeGetWithPoint: (NSArray<NSString*>*) point
    pointsEncoded: (NSNumber*) pointsEncoded
    key: (NSString*) key
    locale: (NSString*) locale
    instructions: (NSNumber*) instructions
    vehicle: (NSString*) vehicle
    elevation: (NSNumber*) elevation
    calcPoints: (NSNumber*) calcPoints
    pointHint: (NSArray<NSString*>*) pointHint
    chDisable: (NSNumber*) chDisable
    weighting: (NSString*) weighting
    edgeTraversal: (NSNumber*) edgeTraversal
    algorithm: (NSString*) algorithm
    heading: (NSNumber*) heading
    headingPenalty: (NSNumber*) headingPenalty
    passThrough: (NSNumber*) passThrough
    roundTripDistance: (NSNumber*) roundTripDistance
    roundTripSeed: (NSNumber*) roundTripSeed
    alternativeRouteMaxPaths: (NSNumber*) alternativeRouteMaxPaths
    alternativeRouteMaxWeightFactor: (NSNumber*) alternativeRouteMaxWeightFactor
    alternativeRouteMaxShareFactor: (NSNumber*) alternativeRouteMaxShareFactor
    completionHandler: (void (^)(SWGRouteResponse* output, NSError* error)) handler {
    // verify the required parameter 'point' is set
    if (point == nil) {
        NSParameterAssert(point);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"point"] };
            NSError* error = [NSError errorWithDomain:kSWGRoutingApiErrorDomain code:kSWGRoutingApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    // verify the required parameter 'pointsEncoded' is set
    if (pointsEncoded == nil) {
        NSParameterAssert(pointsEncoded);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"pointsEncoded"] };
            NSError* error = [NSError errorWithDomain:kSWGRoutingApiErrorDomain code:kSWGRoutingApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    // verify the required parameter 'key' is set
    if (key == nil) {
        NSParameterAssert(key);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"key"] };
            NSError* error = [NSError errorWithDomain:kSWGRoutingApiErrorDomain code:kSWGRoutingApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    NSMutableString* resourcePath = [NSMutableString stringWithFormat:@"/route"];

    NSMutableDictionary *pathParams = [[NSMutableDictionary alloc] init];

    NSMutableDictionary* queryParams = [[NSMutableDictionary alloc] init];
    if (point != nil) {
        queryParams[@"point"] = [[SWGQueryParamCollection alloc] initWithValuesAndFormat: point format: @"multi"];
        
    }
    if (locale != nil) {
        queryParams[@"locale"] = locale;
    }
    if (instructions != nil) {
        queryParams[@"instructions"] = instructions;
    }
    if (vehicle != nil) {
        queryParams[@"vehicle"] = vehicle;
    }
    if (elevation != nil) {
        queryParams[@"elevation"] = elevation;
    }
    if (pointsEncoded != nil) {
        queryParams[@"points_encoded"] = pointsEncoded;
    }
    if (calcPoints != nil) {
        queryParams[@"calc_points"] = calcPoints;
    }
    if (pointHint != nil) {
        queryParams[@"point_hint"] = [[SWGQueryParamCollection alloc] initWithValuesAndFormat: pointHint format: @"multi"];
        
    }
    if (chDisable != nil) {
        queryParams[@"ch.disable"] = chDisable;
    }
    if (weighting != nil) {
        queryParams[@"weighting"] = weighting;
    }
    if (edgeTraversal != nil) {
        queryParams[@"edge_traversal"] = edgeTraversal;
    }
    if (algorithm != nil) {
        queryParams[@"algorithm"] = algorithm;
    }
    if (heading != nil) {
        queryParams[@"heading"] = heading;
    }
    if (headingPenalty != nil) {
        queryParams[@"heading_penalty"] = headingPenalty;
    }
    if (passThrough != nil) {
        queryParams[@"pass_through"] = passThrough;
    }
    if (roundTripDistance != nil) {
        queryParams[@"round_trip.distance"] = roundTripDistance;
    }
    if (roundTripSeed != nil) {
        queryParams[@"round_trip.seed"] = roundTripSeed;
    }
    if (alternativeRouteMaxPaths != nil) {
        queryParams[@"alternative_route.max_paths"] = alternativeRouteMaxPaths;
    }
    if (alternativeRouteMaxWeightFactor != nil) {
        queryParams[@"alternative_route.max_weight_factor"] = alternativeRouteMaxWeightFactor;
    }
    if (alternativeRouteMaxShareFactor != nil) {
        queryParams[@"alternative_route.max_share_factor"] = alternativeRouteMaxShareFactor;
    }
    if (key != nil) {
        queryParams[@"key"] = key;
    }
    NSMutableDictionary* headerParams = [NSMutableDictionary dictionaryWithDictionary:self.apiClient.configuration.defaultHeaders];
    [headerParams addEntriesFromDictionary:self.defaultHeaders];
    // HTTP header `Accept`
    NSString *acceptHeader = [self.apiClient.sanitizer selectHeaderAccept:@[@"application/json"]];
    if(acceptHeader.length > 0) {
        headerParams[@"Accept"] = acceptHeader;
    }

    // response content type
    NSString *responseContentType = [[acceptHeader componentsSeparatedByString:@", "] firstObject] ?: @"";

    // request content type
    NSString *requestContentType = [self.apiClient.sanitizer selectHeaderContentType:@[]];

    // Authentication setting
    NSArray *authSettings = @[];

    id bodyParam = nil;
    NSMutableDictionary *formParams = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *localVarFiles = [[NSMutableDictionary alloc] init];

    return [self.apiClient requestWithPath: resourcePath
                                    method: @"GET"
                                pathParams: pathParams
                               queryParams: queryParams
                                formParams: formParams
                                     files: localVarFiles
                                      body: bodyParam
                              headerParams: headerParams
                              authSettings: authSettings
                        requestContentType: requestContentType
                       responseContentType: responseContentType
                              responseType: @"SWGRouteResponse*"
                           completionBlock: ^(id data, NSError *error) {
                                if(handler) {
                                    handler((SWGRouteResponse*)data, error);
                                }
                            }];
}



@end
