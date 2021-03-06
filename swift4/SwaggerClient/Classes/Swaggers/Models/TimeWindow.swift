//
// TimeWindow.swift
//
// Generated by swagger-codegen
// https://github.com/swagger-api/swagger-codegen
//

import Foundation


public struct TimeWindow: Codable {


    /** Specifies the opening time of the time window in seconds, i.e. the earliest time the service can start. */
    public var earliest: Int64?

    /** Specifies the closing time of the time window in seconds, i.e. the latest time the service can start. */
    public var latest: Int64?
    public init(earliest: Int64?, latest: Int64?) { 
        self.earliest = earliest
        self.latest = latest
    }

}
