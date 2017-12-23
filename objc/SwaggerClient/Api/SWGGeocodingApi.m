#import "SWGGeocodingApi.h"
#import "SWGQueryParamCollection.h"
#import "SWGApiClient.h"
#import "SWGGHError.h"
#import "SWGGeocodingResponse.h"


@interface SWGGeocodingApi ()

@property (nonatomic, strong, readwrite) NSMutableDictionary *mutableDefaultHeaders;

@end

@implementation SWGGeocodingApi

NSString* kSWGGeocodingApiErrorDomain = @"SWGGeocodingApiErrorDomain";
NSInteger kSWGGeocodingApiMissingParamErrorCode = 234513;

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
/// Execute a Geocoding request
/// This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ 
///  @param key Get your key at graphhopper.com 
///
///  @param q If you do forward geocoding, then this would be a textual description of the adress you are looking for. If you do reverse geocoding this would be in lat,lon. (optional)
///
///  @param locale Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn't found the default (en) is used. (optional)
///
///  @param limit Specify the maximum number of returned results (optional)
///
///  @param reverse Set to true to do a reverse Geocoding request (optional)
///
///  @param point The location bias in the format 'latitude,longitude' e.g. point=45.93272,11.58803 (optional)
///
///  @param provider Can be either, default, nominatim, opencagedata (optional)
///
///  @returns SWGGeocodingResponse*
///
-(NSURLSessionTask*) geocodeGetWithKey: (NSString*) key
    q: (NSString*) q
    locale: (NSString*) locale
    limit: (NSNumber*) limit
    reverse: (NSNumber*) reverse
    point: (NSString*) point
    provider: (NSString*) provider
    completionHandler: (void (^)(SWGGeocodingResponse* output, NSError* error)) handler {
    // verify the required parameter 'key' is set
    if (key == nil) {
        NSParameterAssert(key);
        if(handler) {
            NSDictionary * userInfo = @{NSLocalizedDescriptionKey : [NSString stringWithFormat:NSLocalizedString(@"Missing required parameter '%@'", nil),@"key"] };
            NSError* error = [NSError errorWithDomain:kSWGGeocodingApiErrorDomain code:kSWGGeocodingApiMissingParamErrorCode userInfo:userInfo];
            handler(nil, error);
        }
        return nil;
    }

    NSMutableString* resourcePath = [NSMutableString stringWithFormat:@"/geocode"];

    NSMutableDictionary *pathParams = [[NSMutableDictionary alloc] init];

    NSMutableDictionary* queryParams = [[NSMutableDictionary alloc] init];
    if (q != nil) {
        queryParams[@"q"] = q;
    }
    if (locale != nil) {
        queryParams[@"locale"] = locale;
    }
    if (limit != nil) {
        queryParams[@"limit"] = limit;
    }
    if (reverse != nil) {
        queryParams[@"reverse"] = reverse;
    }
    if (point != nil) {
        queryParams[@"point"] = point;
    }
    if (provider != nil) {
        queryParams[@"provider"] = provider;
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
                              responseType: @"SWGGeocodingResponse*"
                           completionBlock: ^(id data, NSError *error) {
                                if(handler) {
                                    handler((SWGGeocodingResponse*)data, error);
                                }
                            }];
}



@end
