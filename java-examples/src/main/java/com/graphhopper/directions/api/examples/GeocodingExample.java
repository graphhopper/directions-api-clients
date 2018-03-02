package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.api.GeocodingApi;
import com.graphhopper.directions.api.client.model.GeocodingLocation;
import com.graphhopper.directions.api.client.model.GeocodingResponse;

/**
 * A simple geocoding request.
 */
public class GeocodingExample {
    public static void main(String[] args) {
        new GeocodingExample().start();
    }

    private void start() {
        GeocodingApi geocoding = new GeocodingApi();
        String key = System.getProperty("graphhopper.key", "");
        try {
            GeocodingResponse geocodingResponse = geocoding.geocodeGet(key, "bautzen", "de", 5, false, "", "default");
            GeocodingLocation loc0 = geocodingResponse.getHits().get(0);
            System.out.println(loc0.getPoint() + ", " + loc0.getName() + ", " + loc0.getCountry() + ", " + loc0.getState());
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }
    }
}
