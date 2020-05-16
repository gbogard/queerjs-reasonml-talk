module Link = {
  [@react.component]
  let make = (~href, ~children) => {
    <a
      href
      onClick={event =>
        if (!event->ReactEvent.Mouse.defaultPrevented
            && event->ReactEvent.Mouse.button == 0
            && !event->ReactEvent.Mouse.altKey
            && !event->ReactEvent.Mouse.ctrlKey
            && !event->ReactEvent.Mouse.metaKey
            && !event->ReactEvent.Mouse.shiftKey) {
          event->ReactEvent.Mouse.preventDefault;
          href->ReasonReactRouter.push;
        }
      }>
      children
    </a>;
  };
};
