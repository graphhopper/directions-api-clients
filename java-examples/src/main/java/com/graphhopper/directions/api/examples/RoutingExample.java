package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.ApiException;
import com.graphhopper.directions.api.client.api.RoutingApi;
import com.graphhopper.directions.api.client.model.RouteResponse;
import com.graphhopper.directions.api.client.model.RouteResponsePath;
import com.graphhopper.directions.api.client.model.RouteResponsePathInstructions;
import com.graphhopper.directions.api.client.model.VehicleProfileId;

import java.util.Arrays;
import java.util.Collections;

/**
 * A simple example for querying the Routing API.
 */
public class RoutingExample {
    public static void main(String[] args) {
        new RoutingExample().start();
    }

    private void start() {
        RoutingApi routing = new RoutingApi();
        routing.setApiClient(GHApiUtil.createClient());
        try {
            RouteResponse rsp = routing.getRoute(Arrays.asList("48.58467,11.57753", "48.572859,11.592464"),
                    Arrays.<String>asList(), Arrays.<String>asList(),
                    VehicleProfileId.CAR, "en", true, Arrays.<String>asList(), false,
                    true, true, false, true, null, false,
                    "fastest", Collections.<Integer>emptyList(), null, null, null,
                    null, null, null, null, null,
                    null, null);
            RouteResponsePath path = rsp.getPaths().get(0);
            RouteResponsePathInstructions instr = path.getInstructions().get(0);
            System.out.println(instr.getText());
        } catch (ApiException ex) {
            System.out.println(ex.getResponseBody());
            throw new RuntimeException(ex);
        }
    }
}
