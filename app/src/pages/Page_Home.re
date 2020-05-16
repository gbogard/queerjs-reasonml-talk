[@react.component]
let make = () => {
  <MainWrapper>
    <h1> "Hello QueerJS!"->React.string </h1>
    <div>
      <p>
        {js|This is a simple web application developed using ReasonML and ReasonReact ✨|js}
        ->React.string
      </p>
      <p>
        {js|Let me walk you through some of Reason's best features 🌈|js}
        ->React.string
      </p>
    </div>
  </MainWrapper>;
};