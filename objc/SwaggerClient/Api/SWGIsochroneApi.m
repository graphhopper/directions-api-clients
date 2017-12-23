#import "SWGIsochroneApi.h"
#import "SWGQueryParamCollection.h"
#import "SWGApiClient.h"
#import "SWGGHError.h"
#import "SWGIsochroneResponse.h"


@interface SWGIsochroneApi ()

@property (nonatomic, strong, readwrite) NSMutableDictionary *mutableDefaultHeaders;

@end

@implementation SWGIsochroneApi

NSString* kSWGIsochroneApiErrorDomain = @"SWGIsochroneApiErrorDomain";
NSInteger kSWGIsochroneApiMissingParamErrorCode = 234513;

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
/// Isochrone Request
/// The GraphHopper Isochrone API allows calculating an isochrone of a locations means to calculate 'a line connecting points at which a vehicle arrives at the same time,' see [Wikipedia](http://en.wikipedia.org/wiki/Isochrone_map). It is also called **reachability** or **walkability**. 
///  @param point Specify the start coordinate 
///
///  @param key Get your key at graphhopper.com 
///
///  @param timeLimit Specify which time the vehicle should travel. In seconds. (optional, default to 600)
///
///  @param distanceLimit Specify which distance the vehicle should travel. In meter. (optional, default to -1)
///
///  @param vehicle Possible vehicles are bike, car, foot and [more](https://graphhopper.com/api/1/docs/supported-vehicle-profiles/) (optional, default to car)
///
///  @param buckets For how many sub intervals an additional polygon should be calculated. (optional, default to 1)
///
///  @param reverseFlow If `false` the flow goes from point to the polygon, if `true` the flow goes from the polygon \"inside\" to the point. Example usage for `false`&#58; *How many potential customer can be reached within 30min travel time from your store* vs. `true`&#58; *How many customers can reach your store within 30min travel time.* (optional, default to false)
///
///  @returns SWGIsochroneResponse*
///
-(NSURLSessionTask*) isochroneGetWithPoint: (NSString*) point
    key: (NSString*) key
    timeLimit: (NSNumber*) timeLimit
    distanceLimit: (NSNumber*) distanceLimit
    vehicle: (NSString*) vehicle
    buckets: (NSNumber*) buckets
    reverseFlow: (NSNumber*) reverseFlow
    completionHandler: (void (^)(SWGIsochroneResponse* output, NSError* error)) handler {
    // verify the required parameter 'point' is set
    if (point == nil) {
        NSParameterAssert(point);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"point"] };
            NSError* error = [NSError errorWithDomain:kSWGIsochroneApiErrorDomain code:kSWGIsochroneApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    // verify the required parameter 'key' is set
    if (key == nil) {
        NSParameterAssert(key);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"key"] };
            NSError* error = [NSError errorWithDomain:kSWGIsochroneApiErrorDomain code:kSWGIsochroneApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    NSMutableString* resourcePath = [NSMutableString stringWithFormat:@"/isochrone"];

    NSMutableDictionary *pathParams = [[NSMutableDictionary alloc] init];

    NSMutableDictionary* queryParams = [[NSMutableDictionary alloc] init];
    if (point != nil) {
        queryParams[@"point"] = point;
    }
    if (timeLimit != nil) {
        queryParams[@"time_limit"] = timeLimit;
    }
    if (distanceLimit != nil) {
        queryParams[@"distance_limit"] = distanceLimit;
    }
    if (vehicle != nil) {
        queryParams[@"vehicle"] = vehicle;
    }
    if (buckets != nil) {
        queryParams[@"buckets"] = buckets;
    }
    if (reverseFlow != nil) {
        queryParams[@"reverse_flow"] = reverseFlow;
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
                              responseType: @"SWGIsochroneResponse*"
                           completionBlock: ^(id data, NSError *error) {
                                if(handler) {
                                    handler((SWGIsochroneResponse*)data, error);
                                }
                            }];
}



@end
