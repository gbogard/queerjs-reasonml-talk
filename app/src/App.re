[@react.component]
let make = () => {

  /**
   * The ReasonReact router returns the current URL as a list of path segments,
   * so we can pattern match on it.
   */
  let url = ReasonReactRouter.useUrl()

  switch (url.path) {
    | [] => <Page_Home />
    | ["meetup"] => <Page_Meetup />
    | _ => <Page_NotFound />
  };
};
